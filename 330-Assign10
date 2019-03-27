/* CSCI 330 - Assignment 10 */
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <cstring>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

int main() {

int pipefd[2], rs, rs2;
char command1[80];
char command2[80];
char buffer[256];
char *args[80] = {};

// read input commands and create loop
	while (strcmp(command1, "quit") == 1) {
cerr << "Enter command 1 (incl. args) or quit: ";
scanf ("%s",command1);
	if (strcmp(command1, "quit") == 0)
	{
	break;
	}
cerr << "Enter command 2 (incl. args): ";
scanf ("%s",command2);

// create pipe
rs = pipe(pipefd);
	if (rs == -1) {
	perror("pipe");
	exit(EXIT_FAILURE);
	}

// fork into 2 processes
rs = fork();
	if (rs == -1) {
	perror("pipe");
	exit(EXIT_FAILURE);
	}

	if (rs == 0) {	// write child
	// close read end of pipe, keep write end open
	close(pipefd[0]);
	// close standard output
	close(1);
	// duplicate write end of pipe into standard output
	dup(pipefd[1]);
	// close write end of pipe
	close(pipefd[1]);
	}
//execute first command
rs = execvp(command1, args);

// create second fork
rs2 = fork();
	if (rs2 == -1) {
	perror("pipe");
	exit(EXIT_FAILURE);
	}

	if (rs2 == 0) {  // read child process
	// close write end of pipe, keep read end open
	close(pipefd[1]);
	// close standard input
	close(0);
	// duplicate read end of pipe into standard input
	dup(pipefd[0]);
	// close read end of pipe
	close(pipefd[0]);
	// read from read end of pipe
	read(0, buffer, sizeof(buffer));
	}
// execute second command
rs2 = execvp(command2, args);
// need some sort of output so that numbers will appear like in example

// wait for children
wait(&rs);
wait(&rs2);
}
return 0;
}
