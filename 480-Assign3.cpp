////////////////////////////////////////
//Name: 	Jorge Mendoza
//zID:		z1643821
//Due:		4/4/2017
//Assignment:	3
////////////////////////////////////////

#include <stdlib.h>
#include <algorithm>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <cstring>

using namespace std;

//////////////////////////////////////////////////////////
//Funtion:	my_strdup()
//Use:		Returns a pointer to a null-terminated
//		byte string, which is a duplicate of the
//		string pointed to by str
///////////////////////////////////////////////////////////
char *my_strdup(const char *str)
        {
        size_t len = strlen(str);
        char *x = (char *)malloc(len+1); 	/* 1 for the null terminator */
        if(!x) return NULL; 			/* malloc could not allocate memory */
        memcpy(x,str,len+1); 			/* copy the string into the new buffer */
        return x;
        }

///////////////////////////////////////////////////////////
//Main Function
///////////////////////////////////////////////////////////

int main()
	{
	while(1)									//Loop until termination
		{
		bool check = false;							//checks for pipe on command line
		bool check2 = false;							//checks parsed piece for symbol
		string token;								//holds the parsed piece
		vector<string> commands, commands2;					//Vectors left and right 4 side of strings

		cout << "Myshell> " << flush;						//Displays the myshell>
		getline(cin,token);
                size_t pos = token.find("||");						//Looks for the pipe symbol
		if(pos != string::npos)							//Set pipe check if found on string
	        	check = true;
		istringstream iss(token);						//Insert string into stream

 		while(iss >> token)							//loop until return
			{

			if (token.find("||") != string::npos )				//Checks to see if token is the pipe symbol
				check2 = true;						//turns on flag

			if (check2 != false)						// If flag set, right side vector filled
				commands2.push_back(token);				// push into right vector

			else								//If no pipe just need one vector
				commands.push_back(token);

			} //end while tokes

		// check if user wants to quit
		if(commands[0] == "quit" || commands[0] == "q")
			return 0;

		else
			{
			if(check == true)				//If pipe flag set
				{
				commands2.erase(commands2.begin());	//erase pipe symbol from vector

				int pipefd[2];				// create array of file descriptors
				if (pipe(pipefd) == -1)			//create pipe
					{
     			   		perror("pipe failed");		// error check for pipe
			        	exit(-1);
    					}

				pid_t leftpid = fork();               	// create fork
				if(leftpid < 0)		 		//error check for fork
					{
					perror("error forking");
					exit(-1);
					}
				else if (leftpid == 0)			//In child Process
					{
					//close unused pipe read
					close(pipefd[0]);
					// close standard output
					close(1);
					// replace stdout by pipe output
					dup(pipefd[1]);
					// close original pipe write
					close(pipefd[1]);

					const size_t array_size1 = commands.size();		// create const array
                			char** arg_array1 = new char*[array_size1 + 1]; 	// extra space for terminating NULL
                			for (size_t s = 0; s < array_size1; s++)		// loop thru to copy elements
                        			{
                        			arg_array1[s] = my_strdup(commands[s].c_str()); //assign using own function
                        			}
                			arg_array1[array_size1] = 0;		// set
					execvp(arg_array1[0], arg_array1);        // execute command using command and args
					cout << "error could not execute command: " << commands[0] << "\n" ;		// should not reach here, error check exec
					exit(-1);
					}
				else 		//parent process
					{
					//Create new process for right side
					pid_t rightpid = fork();         // create fork
					if(rightpid < 0)                 //error check for fork
                                               	{
                                               	perror("error forking");
                                               	exit(-1);
                                               	}
                                       	else if (rightpid == 0)          // child Process
                                               	{
                                               	//close pipe write end
                                               	close(pipefd[1]);
                                               	//close standard input
                                               	close(0);
                                               	// replace stdin by pipe input
                                               	dup(pipefd[0]);
                                               	// close original pipe input
                                               	close(pipefd[0]);

						// create const array
                                               	const size_t array_size2 = commands2.size();
                                               	char** arg_array2 = new char*[array_size2 + 1];   // extra space for terminating NULL
                                               	for (size_t i = 0; i < array_size2; i++)         // loop thru to copy elements
                                                       	{
                                                       	arg_array2[i] = my_strdup(commands2[i].c_str()); //assign using own function
                                                       	}
                                               	arg_array2[array_size2] = 0;              // reset to zero
                                               	execvp(arg_array2[0], arg_array2);        // execute command using command and args
                                               	cout << "error could not execute command: " << commands2[1] << "\n" ;            // should not reach here,$
                                               	exit(-1);
						}//End child process

					else                    //parent process
                                               	{
						close(pipefd[0]);
                                                close(pipefd[1]);

						if(waitpid(leftpid, 0, 0) < 0)        // parent waitng for left child
                                        	      {
                                        	      perror("waitpid error waiting for child");      // error check for wait
                                        	      exit(-1);
                                        	      }

                                              	if(waitpid(rightpid, 0, 0) < 0)  // parent waitng for child
                                                       	{
                                                       	perror("waitpid error waiting for child");      // error check for wait
                                                       	exit(-1);
                                                       	}
						} //End parent process
					}//End-main parent

				}//End-if true check

			else					//If no pipe but simple command
				{
				pid_t pid = fork();         	// create fork

				if(pid < 0)                 	//error check for fork
	                                {
                                        perror("error forking");
                                        exit(-1);
                                        }
				else if (pid == 0)
					{
					// create const array
                                        const size_t array_size = commands.size();
                                        char** arg_array = new char*[array_size + 1];   // extra space for terminating NULL
                                        for (size_t i = 0; i < array_size; ++i)         // loop thru to copy elements
        	                                {
                                                arg_array[i] = my_strdup(commands[i].c_str()); //assign using own function
                                                }
                                        arg_array[array_size] = 0;              // reset to zero
                                        execvp(arg_array[0], arg_array);        // execute command using command and args
					cout << "error could not execute command: " << commands[0] << "\n" ;            // should not reach here, error c$
                                        exit(-1);

					}
				else                    //parent process
                	        	{
                                        if(waitpid(pid, 0, 0) < 0)  // parent waitng for child
                        	                {
                                                perror("waitpid error waiting for child");      // error check for wait
                                                exit(-1);
                                                }

                                        }//end parent process
				}// End-else simple command
			}//END-ELSE not quit
		} //WHILE-END still shell
	} //MAIN-ENDS
