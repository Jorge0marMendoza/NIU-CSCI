/****************************************************************
   PROGRAM:   
   AUTHOR:    
   LOGON ID:  
   DUE DATE:  February 17 2015

   FUNCTION:  Call fork twice to create 3 additional processes and
	      have them print out their PIDs and messages in
	      sequential order using the wait and sleep commands

   INPUT:     None

   OUTPUT:    A list of messages printed by parent, intermediate
	      parent, child, and a system call listing all the 
	      processes involved in this program.

****************************************************************/
#include <iostream>
#include <iomanip>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <cstdlib>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <sstream>

using std::cout;
using std::endl;
using std::string;
using std::stringstream;

int main()
{
	int pid1 = 0;	// variables to hold the fork values
	int pid2 = 0;

	int pido = 0;	// hold pid of original process's parent
	int pid = 0;	// hold pid of original process
	int pidp = 0;	// hold pid of the parent
	int pidip = 0;	// hold pid of the intermediate parent
	int pidc = 0;	// hold pid of the child
	stringstream pids;	// holds stringstream version of pids
	string ids;	// holds string of parent PIDs

	pid1 = fork();	// first fork to make 2 processes
	pid2 = fork();	// second fork to make 4 processes

	if(pid1 > 0 && pid2 > 0)	// original process
	{
		pid = getpid();
		pido = getppid();
		cout << "PARENT: My PID is " << pid << ", my parent's PID is " << pido << ". My Children are " << pid1 << ", " << pid2 << "." << endl;
		pids << pido << "," << pid << "," << pid2  << "," << pid1;	// convert PID to stringstream
		ids = "/bin/ps -f --ppid " + pids.str();
		system(ids.c_str());	//system call to show all the process involved
		waitpid(pid2,0,0);		// wait for child process
		waitpid(pid1,0,0);
		cout << "PARENT: Children process are finished." << endl;
	}
	if(pid1 == 0 && pid2 > 0)	// intermediate process
	{
		pidip = getpid();	
		pid = getppid();
		cout << "INTERMEDIATE PARENT: My PID is " << pidip << ", my parent's PID is " << pid << ". My child is " << pid2 << "." << endl;
		system("sleep 3");	// sleep for 3 seconds
		cout << "INTERMEDIATE PARENT: " << pidip << " is awake." << endl;
	}
	if(pid1 > 0 && pid2 == 0)	// child process
	{
		pidp = getpid();
		pid = getppid();
		cout << "CHILD: My PID is " << pidp << ", my parent's PID is " << pid << "." << endl;
		system("sleep 3");	// sleep for 3 seconds
		cout << "CHILD: " << pidp << " is awake." << endl;
	}
	if(pid1 == 0 && pid2 == 0)	// grandchild process
	{
		pidc = getpid();
		pidip = getppid();
		cout << "CHILD: My PID is " << pidc << ", my parent's PID is " << pidip << "." << endl;
		system("sleep 3");	// sleep for 3 seconds
		cout << "CHILD: " << pidc << " is awake." << endl;
	}

	return 0;
}
