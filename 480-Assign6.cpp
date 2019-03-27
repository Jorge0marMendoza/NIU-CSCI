#include <string>
#include <vector>

#ifndef PHYSICALMEMORY_H
#define PHYSICALMEMORY_H

using namespace std;

/****************************************************************
   PROGRAM:   PhysicalMemory.h
   AUTHOR:    
   LOGON ID:  
   DUE DATE:  April 28 2015

   FUNCTION:  This contains the variables and function headers
	      used in the file PhysicalMemory.cpp

****************************************************************/

class PhysicalMemory
{
	public:
		PhysicalMemory(int memorySize, int algorithmIn);
		void access(int frameID);
		void printMemory() const;
		int swapIn(string item);
	private:
		vector<string> memoryList;	// the physical memory
		vector<int> timeList;		// data structure for the replacement algorithm
		int currentTimeIndex;		// current clock for timestamp
		int algorithmFlag;		// indicate if using FIFO or LRU
		int getNextAvailableFrame();	// get a frame, either available or via replacement
		bool isFull();			// check if the memory is full
		int storeSize;			// store the initial size of lists
};

#endif

#include <string>
#include <vector>

#ifndef PAGETABLE_H
#define PAGETABLE_H

#include "PhysicalMemory.h"
using namespace std;

/****************************************************************
   PROGRAM:   PageTable.h
   AUTHOR:    
   LOGON ID:  
   DUE DATE:  April 28 2015

   FUNCTION:  header file for the cpp version of the page table
 
****************************************************************/

struct PageTableEntry
{
	bool valid;

	int physicalMemoryIndex;
};

class PageTable
{
	public:
		PageTable(PhysicalMemory* pmIn, int tableSize);
		void reference(int pageID, string item);
		int getFaults() const;
		void printTable() const;
		void reset();
	private:
		vector<PageTableEntry> entryList;
		int numFaults;
		PhysicalMemory* mainPhysicalMemory;
		void pageFault(int pageID, string item);
		void updateReplacedEntry(int replacedIndex, int pageID);
};

#endif

/****************************************************************
   PROGRAM:   PhysicalMemory.cpp
   AUTHOR:    
   LOGON ID:  
   DUE DATE:  April 28 2015

   FUNCTION:  This contains the entries of physical frames, which
              can be an array or a vector. They are created by the
              constructor.

****************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include "PhysicalMemory.h"
#include "PageTable.h"

using namespace std;

/***************************************************************
Constructor: PhysicalMemory

Use: initialize all the data and data structure in the class. The
     second argument is for testing different page replacement
     algorithms.

Arguments: int

Returns: none
***************************************************************/
PhysicalMemory::PhysicalMemory(int memorySize, int algorithmIn)
{
	currentTimeIndex = 0;
	algorithmFlag = algorithmIn;
	storeSize = memorySize;		// store the initial memory size
	for(int i = 0; i < memorySize; i++)
	{
		memoryList.push_back("");	// set entire list to NULL
		timeList.push_back(-1);
	}
}

/***************************************************************
Function: access

Use: access the frame, update the time stamp and time list

Arguments: int

Returns: void
***************************************************************/
void PhysicalMemory::access(int frameID)
{
	cout << "Physical: Access FrameID: " << frameID << " contains: " << memoryList.at(frameID) << endl;	//access the frame
	timeList.at(frameID) = currentTimeIndex;   // update time list
}

/***************************************************************
Function: printMemory

Use: print out the physical memory layout

Arguments: const

Returns: void
***************************************************************/
void PhysicalMemory::printMemory() const
{
	for(int i = 0; i < memoryList.size(); i++)      // loop through the physical memory
	{
		cout << "Physical: Memory Spot: " << i << " contains: " << memoryList.at(i) << endl;
	}
}

/***************************************************************
Function: swapIn

Use: returns the frame ID of the item just swapped in

Arguments: string

Returns: int
***************************************************************/
int PhysicalMemory::swapIn(string item)
{
	int frameID = getNextAvailableFrame();
	cout << "Physical: Stored: " << item << endl;
	memoryList.at(frameID) = item;             // update memory list
	timeList.at(frameID) = currentTimeIndex;   // update time list
	currentTimeIndex++;			   // update time stamp
	return frameID;
}

/***************************************************************
Function: getNextAvailableFrame

Use: get a frame, either available or via replacement

Arguments: none

Returns: int
***************************************************************/
int PhysicalMemory::getNextAvailableFrame()
{
	if(isFull())	// memory is full
	{
		int oldest = currentTimeIndex;
		int frameID = -1;
		for(int i = 0; i < timeList.size(); i++)
		{
			if(timeList.at(i) < oldest)	// compare old time with store time
			{
				frameID = i;
				oldest = timeList.at(i);
			}
		}
		return frameID;
	}
	else		// empty slot available
	{
		int counter = 0;
		while(timeList.at(counter) != -1)
		{
			counter++;
		}
		return counter;
	}
}

/***************************************************************
Function: isFull

Use: check if the memory is full

Arguments: none

Returns: bool
***************************************************************/
bool PhysicalMemory::isFull()
{
	if(storeSize != memoryList.size())
	{
		return false;
	}
	else
	{
		return true;
	}
}

/****************************************************************
   PROGRAM:   PageTable.cpp
   AUTHOR:    
   LOGON ID:
   DUE DATE:  April 28 2015

   FUNCTION:  creates the page table, tracks the number of page
              faults, and connects the table to the physical
              memory.  Maps the memory so the driver has access
              to the information it requires.

****************************************************************/

#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include "PageTable.h"
#include "PhysicalMemory.h"

using namespace std;

/***************************************************************
Constructor: PageTable

Use:  initialize all entries to invalid

Arguments: PhysicalMemory*, int

Returns: PageTable
***************************************************************/
PageTable::PageTable(PhysicalMemory* pmIN, int tableSize)
{
	mainPhysicalMemory = pmIN;
	numFaults = 0;
	entryList.resize(tableSize);            // set entry list size
	PageTableEntry TblEntry;		// initalize the struct
	for(int i = 0;	i < tableSize;	i++)	// add all entries to list
	{
		TblEntry.valid = false;
		TblEntry.physicalMemoryIndex = i;
		entryList.push_back(TblEntry);
	}
}

/***************************************************************
Function: reference

Use: reference a logical page, if not in memory, call pageFault

Arguments: int, string

Returns: none
***************************************************************/
void PageTable::reference(int pageID, string item)
{
	if(entryList.at(pageID).valid == true)	// page found in memory
	{
		mainPhysicalMemory->access(entryList.at(pageID).physicalMemoryIndex);
	}
	else					// page not found in memory
	{
		pageFault(pageID, item);
	} 
}

/***************************************************************
Function: getFaults

Use: return the number of faults

Arguments: const

Returns: int
***************************************************************/
int PageTable::getFaults() const
{
	return numFaults;
}

/***************************************************************
Function: printTable

Use: print the layout of the page table

Arguments: const

Returns: none
***************************************************************/
void PageTable::printTable() const
{
	for(int i = 0; i < entryList.size(); i++)       // loop through the page table
	{
		cout << "PageTable: Index: " << i << " : Physical Index : " << entryList.at(i).physicalMemoryIndex << " : In Use : ";
		if(entryList.at(i).valid == false)		// change the flag into character font
		{
			cout << "false" << endl;
		}
		else
		{
			cout << "true" << endl;
		}
	}
	cout << "PageTable: Current number of pagefaults: " << getFaults() << endl;	// print number of faults
}

/***************************************************************
Function: reset

Use: reset the validity flag to false and number of faults to 0

Arguments: none

Returns: void
***************************************************************/
void PageTable::reset()
{
	for(int i = 0; i < entryList.size(); i++)		// loop through entry list
	{
		entryList.at(i).valid = false;
	}
	numFaults = 0;
}

/***************************************************************
Function: pageFault

Use: increment numFaults; need to swap in the item into physical
     memory by calling the swapIn() of the PhysicalMemory class

Arguments: int, string

Returns: void
***************************************************************/
void PageTable::pageFault(int pageID, string item)
{
	numFaults++;                    // increment number of faults
	cout << "PageTable: Page Fault Occurred" << endl;
	int SwapIndex = mainPhysicalMemory->swapIn(item);	// store frame ID to swap into page table
	for(int i = 0; i <  entryList.size(); i++)		// loop through entry list
	{
		if(SwapIndex == entryList.at(i).physicalMemoryIndex)
		{
			updateReplacedEntry(i,pageID);		// update page table
		}
	}
	entryList.at(pageID).physicalMemoryIndex = SwapIndex;
}

/***************************************************************
Function: updateReplacedEntry

Use: after page replacement, update the page table correspondingly
     by making the original mapping for the frame invalid

Arguments: int

Returns: void
***************************************************************/
void PageTable::updateReplacedEntry(int replacedIndex, int pageID)
{
	entryList.at(replacedIndex).physicalMemoryIndex = -1;
	entryList.at(replacedIndex).valid = false;
	entryList.at(pageID).valid = true;
}



