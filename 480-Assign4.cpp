/*////////////////////////////////////////////////
NAME:		Jorge Mendoza			//
ZID:						//
DUE:						//
USE:		Reads from a file		//
		writes to binary file		//
		and finally prints		//
		the details, and totals		//
/*////////////////////////////////////////////////

#include <stdlib.h>
#include <algorithm>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <string>
#include <iostream>
#include <fstream>
#include <sys/stat.h>
#include <sstream>
#include <cstring>
#include <boost/regex.hpp>
#include <ios>         // std::unitbuf

using namespace std;

int main(int argc, char *argv[])
	{

	cout << unitbuf;							// Sets the flag for the str stream
	ifstream infile;							// Initialize stream
	ostringstream outStream;
	stringstream inStream;
	string temp;
	int linesize;
	char lineLength[3];
	char outRecord[300];
	char inRecord[300];
	char recordSize[3];
	string record;
	string myfile;  							// Default file to read
	int recordCnt = 0;							// Keeps track of records

	int pipefd[2];          	        				// create array of file descriptors
	if (pipe(pipefd) == -1)                 				// Create pipe
		{
		perror("pipe failed");          				// Error check for pipe
              	exit(-1);
              	}

	pid_t pid = fork();            						// Create a process using fork
	if(pid < 0)                   						// Error check for fork
         	{
                perror("error forking");
                exit(-1);
                }

	else if (pid == 0)  /////////////////////////////// Child Process
        	{
		close(pipefd[1]);                                               // Close unused pipe write

		while(read(pipefd[0],recordSize,3) != 0)			// Loop until size 0 or no records
			{
			int recordLength = atoi(recordSize);			// Covert record size to int
			read(pipefd[0], inRecord, recordLength);
			outStream << " Child: Reading: " << recordLength << " bytes: " << inRecord << "\n";

			cout << outStream.str();
			outStream.clear();
                	outStream.str("");
			}
		close(pipefd[0]);						// CLose read end, done reading

		}

	else  /////////////////////////////////////////// Parent process
        	{
		close(pipefd[0]);						// Close unused pipe read
		if (argc > 1)            	                                // If command line has file
    			{
			infile.open(argv[1]);					// Open command line file
			if (!infile)						// Error check file
   				{
     				cout << "Can't open\n";
     				exit(-1);
   				}
			myfile = argv[1];	                                // Set filename to command line arguement
    			}
		else                                             		// If no text file use default
    			{
    			infile.open("/home/turing/t90rkf1/d480/dhw/hw4-air/resv.txt");					// Open the default file
    			if(!infile)                                             // Error testing
      				{
      				cout << "Error: Cannot open default file." << endl;
      				exit(-1);                                        // Exit if not opened
      				}
			myfile = "/home/turing/t90rkf1/d480/dhw/hw4-air/resv.txt";
    			}

	 	while(getline(infile,record))
			{
			recordCnt++;
			linesize = record.length();
			if(record.length() >= 100)
				{
                        	inStream << "000";
                        	inStream << record.length();
                        	inStream >> temp;
                        	strcpy(lineLength,temp.c_str()+3);
				}
			else
				{
				inStream << "000";
                                inStream << record.length();
                                inStream >> temp;
                                strcpy(lineLength,temp.c_str()+2);
				}

			write(pipefd[1], lineLength, 3);

			inStream.clear();
                	inStream.str("");
			inStream << record;
			inStream >> temp;
			outStream << "Parent: Writing: " << record << "\n";

                        cout << outStream.str();
                        outStream.clear();
                        outStream.str("");

			strcpy(outRecord,temp.c_str());
			write(pipefd[1],outRecord,linesize);

			inStream.clear();
	                inStream.str("");
			}// End-Getline

		infile.clear();
		infile.close();
		close(pipefd[1]);						// Close write end , finished writting

		if(waitpid(pid, 0, 0) < 0)  					// Parent waitng for child
                	{
			perror("waitpid error waiting for child"); 		// Error check for wait
                      	exit(-1);
                      	}

		}//End-Parent

	return 0;
  	}//End-MAIN

