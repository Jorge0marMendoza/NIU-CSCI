/****************************************************************
   PROGRAM:   
   AUTHOR:    
   LOGON ID: 
   DUE DATE:  January 30 2015

   FUNCTION:  Reads the two virtual files /proc/cpuinfo and
              /proc/uptime in order to print out the answers
              to a list of questions.

   INPUT:     location of input, i.e.  standard input, a file on
              disk

   OUTPUT:    The answers to the list of questions given.

****************************************************************/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <sys/utsname.h>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <stdlib.h>
#include <algorithm>			// http://www.cplusplus.com/reference/algorithm/unique/
#include <stdio.h>
#include <time.h>			// http://www.cplusplus.com/reference/ctime/gmtime/

using std::ifstream;
using std::istream;
using std::cout;
using std::endl;
using std::string;
using std::size_t;
using std::unique;
using std::strcpy;
using std::vector;
using std::getline;

/****************************************************************

   FUNCTION:   getOStype

   ARGUMENTS:  None

   RETURNS:    String

   NOTES:      Opens a file and stores all the data present as
	       a string. Returns the string to the main function
****************************************************************/
string getOStype()
{
	ifstream inFile;
	string ostype;

	inFile.open("/proc/sys/kernel/ostype");
		if(!inFile)                     // error testing
		{
			cout << "Error: Cannot open file." << endl;
			exit(1);
		}
		while(!inFile.eof())
		{
			getline(inFile,ostype);         // type of operating system
			return ostype;
		}
	inFile.close();

	return ostype;
}

/****************************************************************

   FUNCTION:   getHostName

   ARGUMENTS:  None

   RETURNS:    String

   NOTES:      Opens a file and stores all the data present as
               a string. Returns the string to the main function
****************************************************************/
string getHostName()
{
	ifstream inFile;
	string hostname;

	inFile.open("/proc/sys/kernel/hostname");
		if(!inFile)                     // error testing
		{
			cout << "Error: Cannot open file." << endl;
			exit(1);
		}
		while(!inFile.eof())
		{
			getline(inFile,hostname);       // hostname of the system
			return hostname;
		}
	inFile.close();

	return hostname;
}

/****************************************************************

   FUNCTION:   getOSrelease

   ARGUMENTS:  None

   RETURNS:    String

   NOTES:      Opens a file and stores all the data present as
               a string. Returns the string to the main function
****************************************************************/
string getOSrelease()
{
	ifstream inFile;
	string osrelease;

	inFile.open("/proc/sys/kernel/osrelease");
		if(!inFile)                     // error testing
		{
			cout << "Error: Cannot open file." << endl;
			exit(1);
		}
		while(!inFile.eof())
		{
			getline(inFile,osrelease);      // release date of operating system
			return osrelease;
		}
	inFile.close();

	return osrelease;
}

/****************************************************************

   FUNCTION:   getVersion

   ARGUMENTS:  None

   RETURNS:    String

   NOTES:      Opens a file and stores all the data present as
               a string. Returns the string to the main function
****************************************************************/
string getVersion()
{
	ifstream inFile;
	string version;

	inFile.open("/proc/sys/kernel/version");
		if(!inFile)                     // error testing
		{
			cout << "Error: Cannot open file." << endl;
		}
		while(!inFile.eof())
		{
			getline(inFile,version);        // version number of operating system
			return version;
		}
	inFile.close();

	return version;
}

int main() 
{
	ifstream inFile; 			// object for reading from input file
	string cpuinfo;				// memory where cpu file is stored
	string uptime;				// memory where time file is stored
/*********************
  Part A Variables
*********************/
	int processor = 0;			// counter for processors
	vector<string> chipID;			// list of current chip IDs
	int chip = 0;				// counter for multi-core chips
	string core;				// stores the number of cores
	string cache;				// choice between L2 and L3	
	string seconds;				// uptime of the process
	int scnd;				// integer value of seconds
/********************
  Part B Variables
********************/
	string point;				// Yes or no for floating point
	string cache_size;			// size of the cache in KB
	string vendor;				// name of the vendor
	string model;				// model name of machine
	string speed;				// speed of machine in MHz
	string cache_align;			// cache alignment
	string psize;				// size of physical address
	string vsize;				// size of virtual address
/*******************
  Part C Variables
*******************/
	string ostype;				// operating system type
	string hostname;			// host name
	string osrelease;			// release date of operating system
	string version;				// version of the machine
/*******************
  Part D Variables
*******************/
	struct utsname partD;
	uname(&partD);
/********************
  Main Program
********************/

	inFile.open("/proc/cpuinfo");		// open the file
		if(!inFile)			// error testing
		{
			cout << "Error: Cannot open file." << endl;
			exit(1);
		}
		
		while(!inFile.eof())
		{
			getline(inFile, cpuinfo);	//  retrieve data from file

			if(cpuinfo.find("processor") == 0)	// finds all the positions of processor
			{
				processor++;
			}

			if(cpuinfo.find("physical id") == 0)	// finds line with the chip ID number
			{
				size_t position = cpuinfo.find(":") + 2;	// find the ID number
				chipID.push_back(cpuinfo.substr(position));	// store ID number for test	
			}

			if(cpuinfo.find("cpu cores") == 0)	// finds line about the cores
			{
				size_t position = cpuinfo.find(":") + 2;	// find number of cores
				core = cpuinfo.substr(position);		// store the number of cores
				if(core == "2")
				{
					cache = "L2";				// sets the cache to L2
				}
			}

			if(cpuinfo.find("fpu") == 0)				// find floating point unit
			{
				size_t position = cpuinfo.find(":") + 1;
				point = cpuinfo.substr(position);		// store fpu answer
			}

			if(cpuinfo.find("cache size") == 0)			// find the cache size
			{
				size_t position = cpuinfo.find(":") + 1;
				cache_size = cpuinfo.substr(position);		// retrieve cache size from file
			}

			if(cpuinfo.find("vendor_id") == 0)			// find the vendor name
			{
				size_t position = cpuinfo.find(":") + 1;		
				vendor = cpuinfo.substr(position);		// store name of vendor
			}

			if(cpuinfo.find("model name") == 0)			// find the model name
			{
				size_t position = cpuinfo.find(":") + 1;
				model = cpuinfo.substr(position);		// store the model name
			}

			if(cpuinfo.find("cpu MHz") == 0)			// find the machine speed
			{
				size_t position = cpuinfo.find(":") + 1;
				speed = cpuinfo.substr(position);
			}

			if(cpuinfo.find("cache_alignment") == 0)		// find alignment title
			{
				size_t position = cpuinfo.find(":") + 1;
				cache_align = cpuinfo.substr(position);
			}

			if(cpuinfo.find("address sizes") == 0)			// find physical and virtual addresses
			{
				size_t position1 = cpuinfo.find(":") + 1;	// find position of size
				psize = cpuinfo.substr(position1, 8);
				size_t position2 = position1 + 18;		// move to positions of virtual
				vsize = cpuinfo.substr(position2, 8);
			}
		}
	chipID.erase(unique(chipID.begin(),chipID.end()),chipID.end());		// delete duplicates
	chip = chipID.size();

	inFile.close();

	inFile.open("/proc/uptime");		// opened the time file
		if(!inFile)                     // error testing
		{
			cout << "Error: Cannot open file." << endl;
			exit(1);
		}

		while(!inFile.eof())
		{
			getline(inFile,uptime);
			seconds = uptime.substr(0,uptime.find(" "));	// find length of time string
			int templength = seconds.size() - 2;		// find lenght of string
			char sec[10];					// Cstring for seconds
			for(int i = 0; i <= templength; i++)		// change string to cstring
			{
				sec[i]=seconds[i];
			}
			scnd = atoi(sec);				// convert to integer	
		}

	inFile.close();
		
	time_t second(scnd);				// convert interger to time
	tm *p = gmtime(&second);			// call time function
	// http://stackoverflow.com/questions/2419562/convert-seconds-to-days-minutes-and-seconds

	ostype = getOStype();	// function to get the Operating System type
	hostname = getHostName();	// function to get the Host Name
	osrelease = getOSrelease();	// function to get the Operating System release
	version = getVersion();	// function to get the version of the Operating System

	
	
/*************************************************************************************************************
	Output for Questions
*************************************************************************************************************/
	cout << "A: Questions about hopper:" << endl
	     << "1. Hopper has " << processor << " processors." << endl
	     << "2. Hopper has " << chip << " physical multi-core chip." << endl
	     << "3. Hopper share the " << cache << " cache." << endl
	     << "4. It has been " << scnd << " seconds." << endl
	     << "5. " << p->tm_yday << " days, " << p->tm_hour << " hours, " << p->tm_min << " minutes, and " << p->tm_sec << " seconds." << endl << endl;

	cout << "B. For processor 0, answer these questions:" << endl
	     << "1. Floating Point Unit:" << point << "." << endl
	     << "2. The cache is" << cache_size << "." << endl
	     << "3. The vendor is" << vendor << "." << endl
	     << "4. The model name is" << model << "." << endl
	     << "5. The speed of the cpu is" << speed << " MHz." << endl
	     << "6. The cache alignment is" << cache_align << "." << endl
	     << "7. The physical address size is" << psize << "." << endl
	     << "8. The virtual address size is" << vsize << "." << endl << endl;

	cout << "C. Print the following information from files in /proc/sys/kernel:" << endl
	     << "1. ostype: " << ostype << endl
	     << "2. hostname: " << hostname << endl
	     << "3. osrelease: " << osrelease << endl
	     << "4. version: " << version << endl << endl;

	cout << "D. Call uname and print the following fields:" << endl
	     << "1. sysname: " << partD.sysname << endl
	     << "2. nodename: " << partD.nodename << endl
	     << "3. release: " << partD.release << endl
	     << "4. version: " << partD.version << endl
	     << "5. machine: " << partD.machine << endl;

	return 0;
}
