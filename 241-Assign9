#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <string>
#include <cstdlib>
#include <stdexcept>
#include <vector>

using std::ostream;
using std::cout;
using std::cin;
using std::endl;
using std::ifstream;
using std::setw;
using std::out_of_range;
using std::vector;


//******************************************************************
// FILE:      Quicksort.h
// AUTHOR:    
// LOGON ID:  
// DUE DATE:  December 5 2012
//
// PURPOSE:   Contains the declaration for the quick sort functions.
//******************************************************************

// Function prototypes
template <class T> bool lessThan(const T&, const T&);
template <class T> bool greaterThan(const T&, const T&);
template <class T> void buildList(vector<T>&, const char*);
template <class T> void printList(const vector<T>&, int, int);
template <class T> void sortList(vector<T>&, bool (*)(const T&, const T&));
template <class T> void quickSort(vector<T>&, int, int, bool (*)(const T&, const T&));
template <class T> int partition(vector<T>&, int, int, bool (*)(const T&, const T&));

/***************************************************************
Function declarations
***************************************************************/
/***************************************************************
Function: lessThan

Use: tests if item1 is less than item2

Arguments: const T&

Returns: bool

Notes: None
***************************************************************/
template <class T>
bool lessThan(const T& item1, const T& item2)
{
        if(item1 < item2)
        {
        return true;
        }
        else
        {
        return false;
        }
}
/***************************************************************
Function: greaterThan

Use: tests if item1 is greater than item2

Arguments: const T&

Returns: bool

Notes: None
***************************************************************/
template <class T>
bool greaterThan(const T& item1, const T& item2)
{
        if(item1 > item2)
        {
        return true;
        }
        else
        {
        return false;
        }
}
/***************************************************************
Function: buildList

Use: reads items from an input file and put them into a vector.

Arguments: vector<T>&, const char*

Returns: None

Notes: None
***************************************************************/
template <class T>
void buildList(vector<T>& set, const char* fileName)
{
T item;
ifstream inFile;
inFile.open(fileName);
        if (!inFile)
        {
        cout << "Error: file cannot be opened" << endl;
        exit(1);
        }
inFile >> item;
        while(inFile)
        {
        set.push_back(item);
        inFile >> item;
        }
inFile.close();
}
/***************************************************************
Function: printList

Use: prints a list of items sotred in a vector.

Arguments: const vector<T>&, int

Returns: None

Notes: None
***************************************************************/
template <class T>
void printList(const vector<T>& set, int itemWidth, int numPerLine)
{
        for(int i = 0; i < (int) set.size(); i++)
        {
                if(i % numPerLine == 0)
                {
                cout << endl;
                }
        cout << setw(itemWidth) << set[i];
        }
}
/***************************************************************
Function: sortList

Use: sort the items in the vector set using quick sort

Arguments: vector<T>&, bool

Returns: None

Notes: None
***************************************************************/
template <class T>
void sortList(vector<T>& set, bool (*compare)(const T&, const T&))
{
quickSort(set, 0, (int) set.size() - 1, compare);
}
/***************************************************************
Function: quickSort

Use: performs a recursive calls to implement into the quick sort

Arguments: vector<T>&, int, bool

Returns: None

Notes: None
***************************************************************/
template <class T>
void quickSort(vector<T>& set, int start, int end, bool (*compare)(const T&, const T&))
{
int pivotPoint;
        if(start < end)
        {
        pivotPoint = partition(set, start, end, compare); // Get the pivot Point
        quickSort(set, start, pivotPoint - 1, compare); // Sort first sublist
        quickSort(set, pivotPoint + 1, end, compare); // Sort second sublist
        }
}
/***************************************************************
Function: Partition

Use: selects a pivot element and then partitions the vector
     around the pivot.

Arguments: vector<T>&, int, bool

Returns: int

Notes: None
***************************************************************/
template <class T>
int partition(vector<T>& set, int start, int end, bool (*compare)(const T&, const T&))
{
int pivotIndex, mid;
T pivotValue;
mid = (start + end) / 2;

// Swap elements start and mid of the vector
temp = set[start];
set[start] = set[mid];
set[mid] = temp;

pivotIndex = start;
pivotValue = set[start];
        for(int scan = start + 1; scan <= end; scan++)
        {
                if(compare(set[scan], pivotValue))
                {
                pivotIndex++;
                // Swap elements pivotIndex and scan of the vector
                temp = set[pivotIndex];
                set[pivotIndex] = set[scan];
                set[scan] = temp;
                }
        }
// Swap elements start and pivotIndex of the vector
temp = set[start];
set[start] = set[pivotIndex];
set[pivotIndex] = set[start];

return pivotIndex;
}

#endif
