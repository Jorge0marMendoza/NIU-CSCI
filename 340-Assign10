#ifndef H_TABLEUTIL_H
#define H_TABLEUTIL_H

/****************************
PROGRAM: hTable-util.h
PROGRAMMER: 

****************************/

void ptr_sort(vector <Entry*> &pTable, unsigned int);
void ptr_sort(vector <Entry*>); // sorts the points
bool predicate(Entry*, Entry*);
#endif


#include "/home/onyuksel/courses/340/progs/13s/p10/hTable.h"
#include "hTable-util.h"

#ifndef H_TABLEUTIL
#define H_TABLEUTIL

/*******************************
PROGRAM: hTable-util.cc
PROGRAMMER: 

*******************************/

/*****************************************************************
Function: ptr_sort

Use: sort pointer table

Arguments: vector <Entry*>

Returns: void
******************************************************************/
void prt_sort(vector <Entry*> pTable)
{
        sort(pTable.begin(), pTable.end(), predicate);
}
/****************************************************************
Function: predicate

Use: predicate for pointer table sort function

Arguments: Entry*

Returns: void
******************************************************************/
bool predicate(Entry* left, Entry* right)
{
        if(left->key < right->key)
        {
                return true;
        }
        return false;
}
/****************************************************************
Function: ptr_sort

Use: sort pointer table

Arguments: vector <Entry*>, int

Returns: void
******************************************************************/
void ptr_sort(vector <Entry*> &pTable, unsigned int psize)
{
        unsigned int i, j;
        Entry* bucket;
                for (i = 1; i < psize; i++)
                {
                        bucket = pTable[i];
                                for (j = i; (j > 0) && (pTable[j-1]->key > bucket->key); j--)
                                {
                                        pTable[j] = pTable[j-1];
                                }
                        pTable[j] = bucket;
                }
}
#endif



#include "/home/onyuksel/courses/340/progs/13s/p10/hTable.h"
#include "hTable-util.h"

#ifndef H_TABLE
#define H_TABLE

/***************************
PROGRAM: hTable.cc
PROGRAMMER:
***************************/

/***************************************************************
Constructor: HT

Use: initialize all items in the class

Arguments: const unsigned&

Returns: None
***************************************************************/
HT::HT(const unsigned& x)
{
        hTable.resize(x);
        pTable.resize(x);
        psize = 0;
        hsize = TBL_SZ;
                for(unsigned int i = 0; i != x; i++)
                {
                        hTable[i].key = FREE;
                }
}
/***************************************************************
Destructor: ~HT

Use: cleans the tables.

Arguments: None

Returns: None
***************************************************************/
HT::~HT()
{
        hTable.clear();
        pTable.clear();
}
/***************************************************************
Function: insert

Use: insert the record for an item in the hash table. If the key
     already exists in the table, the function prints an error
     message; if the table is full, it also prints an error
     message; otherwise, it prints the index value of the inserted
     record in the hash table and inserts the address of the
     record in the hash table into the pointer table.

Arguments: const Entry&

Returns: void
******************************************************************/
void HT::insert(const Entry& x)
{
        int i = hash(x.key);    // hash the argument and store in variable
                for(int j = 0; (unsigned) j < hsize; j++)
                {
                        if(hTable[(i+j)%hsize].key == FREE)     // test is spot in table is free
                        {
                                cout << " entry =  " << (i + j) % hsize << endl;
                                hTable[(i+j)%hsize] = x;
                                pTable[psize] = &hTable[(i+j)%hsize];
                                psize++;
                                break;
                        }
                        if(hTable[(i+j)%hsize].key == x.key)
                        {
                                cout << " not inserted - duplicate key" << endl;
                                break;
                        }
                        if((unsigned) j == hsize)
                        {
                                cout << " not inserted - table full!" << endl;
                                break;
                        }
                }
}
/****************************************************************
Function: search

Use: search the hash table for a record with a given key. If the
     search is successful, the function prints the item information
     for the record; otherwise, it prints an error message.

Arguments: const string&

Returns: void
******************************************************************/
void HT::search(const string& s)
{
        int i = hash(s);
        unsigned int j;
                for(j = 0; j < hsize; j++)
                {
                        if(hTable[(i+j)%hsize].key == s)
                        {
                                cout << " ==> number: " << setw(4)
                                     << hTable[(i+j)%hsize].num << " - item: "
                                     << hTable[(i+j)%hsize].desc << endl;
                                break;
                        }
                }
                if(hTable[(i+j)%hsize].key != s)
                {
                        cout << " not in table!" << endl;
                }
}
/****************************************************************
Function: hTable_print

Use: print the subscript and the contents of all the active
     records in the hash table

Arguments: None

Returns: void
******************************************************************/
void HT::hTable_print()
{
        bool lstEmpty = false;
                for(int i = 0; (unsigned) i < hsize; i++)
                {
                        if(hTable[i].key != FREE)
                        {
                                if(lstEmpty)
                                {
                                        cout << endl;
                                }
                                cout << setw(4) << i << ": " << hTable[i].key << " - " << setw(5) << hTable[i].num << " - " << hTable[i].desc << endl;
                                lstEmpty = false;
                        }
                        else
                        {
                        lstEmpty = true;
                        }
                }
        cout << endl;
}
/****************************************************************
Function: pTable_print

Use: print the contents of all the active records in the hash
     table in ascending order with the keys of the records.

Arguments: vector <T>&, const char*

Returns: void
******************************************************************/
void HT::pTable_print()
{
        ptr_sort(pTable, psize);
                for(unsigned int i = 0; i < psize; i++)
                {
                        cout << " " << pTable[i]->key << " - " << right << setw(4) << pTable[i]->num << " - " << left << pTable[i]->desc << endl;
                }
        cout << endl;
}
#endif
