#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <cstdlib>
#include <stdexcept>
#include "Stack.h"

using std::ostream;
using std::cout;
using std::cin;
using std::endl;
using std::out_of_range;

/*********************************************************************
PROGRAM:    Stack.cpp
PROGRAMMER: 
LOGON ID:   
DUE DATE:   November 1 2012

FUNCTION:   This program creates and store all the methods used in
            the Stack class
*********************************************************************/

/***************************************************************
Constructor1: Stack

Use: sets all elements of the program to null.

Arguments: None

Returns: None

Notes: None
***************************************************************/
Stack::Stack()
{
stkCap = 1;
stkTop = -1;
stkSize = 0;
stkArray = new int[stkCap];
}
/***************************************************************
Destructor: ~Stack

Use: deletes the memory for stkArray.

Arguments: None

Returns: None

Notes: None
***************************************************************/
Stack::~Stack()
{
delete[] stkArray;
}
/***************************************************************
Constructor2: Stack

Use: create a new object that is the same as the existing one

Arguments: None

Returns: None

Notes: None
***************************************************************/
Stack::Stack(const Stack& s)
{
stkCap = s.stkCap;
stkSize = s.stkSize;
stkArray = new int[stkCap];
        for(int i = 0; i < stkSize; i++)
        {
        stkArray[i] = s.stkArray[i];
        }
stkTop = s.stkTop;
}
/***************************************************************
Method: operator=

Use: allow one Stack to be assigned to another

Arguments: const

Returns: const

Notes: None
***************************************************************/
const Stack& Stack::operator=(const Stack& rightOp)
{
        if(this != &rightOp)
        {
        stkSize = rightOp.stkSize;
        delete[] stkArray;
        stkTop = rightOp.stkTop;
        stkCap = rightOp.stkCap;
        stkArray = new int [stkCap];
                for(int i = 0; i < stkSize; i++)
                {
                stkArray[i] = rightOp.stkArray[i];
                }
        }
return *this;
}
/*********************************************************
Method: clear

Use: set the data members back to the initial state

Arguments: None

Returns: None

Notes: None
****************************************************************/
void Stack::clear()
{
delete[] stkArray;
stkSize = 0;
stkCap = 1;
stkTop = -1;
stkArray = new int[stkCap];
}
/***************************************************************
Method: size

Use: return the stack size

Arguments: None

Returns: int

Notes: None
****************************************************************/
int Stack::size() const
{
return stkSize;
}
/***************************************************************
Method: capacity

Use: returns the stack capcity

Arguments: None

Returns: int

Notes: None
****************************************************************/
int Stack::capacity() const
{
return stkCap;
}
/***************************************************************
Method: empty

Use: tests if the stack is empty or not

Arguments: None

Returns: bool

Notes: None
****************************************************************/
bool Stack::empty() const
{
        if(stkSize == 0)
        {
        return true;
        }

        else
        {
        return false;
        }
}
/***************************************************************
Method: top()

Use: returns the top element of the stack array

Arguments: None

Returns: int

Notes: None
****************************************************************/
int Stack::top() const
{
        if(stkSize == 0)
        {
        throw out_of_range ("Stack is empty");
        }
return stkArray[stkTop];
}
/***************************************************************
Method: push()

Use: inserts an item into the stack

Arguments: int

Returns: None

Notes: None
****************************************************************/
void Stack::push(int item)
{
        if(stkSize == stkCap)
        {
        resize(2 * stkCap);
        }
stkTop++;
stkArray[stkTop] = item;
stkSize++;
}
/***************************************************************
Method: pop()

Use: decrements the tack top subscript to remove the top item

Arguments: None

Returns: None

Notes: None
****************************************************************/
void Stack::pop()
{
        if(stkTop == -1)
        {
        throw out_of_range ("Stack is empty");
        }
stkTop--;
stkSize--;
        if(stkSize > 0 && stkSize == stkCap/4)
        {
        resize(stkCap / 2);
        }
}
/***************************************************************
Method: resize()

Use: resizes the array to fit all items

Arguments: int

Returns: None

Notes: None
****************************************************************/
void Stack::resize(int newCap)
{
stkCap = newCap;
int* copyArray = new int[stkCap];
        for(int i = 0; i < stkSize; i++)
        {
        copyArray[i] = stkArray[i];
        }
delete[] stkArray;
stkArray = copyArray;
}
/***************************************************************
Function: operator<<

Use: Stack can be printed on the standard output.

Arguments: const

Returns: None

Notes: None
***************************************************************/
ostream& operator<<(ostream& leftOp, const Stack& rightOp)
{
        for(int i = 0; i < rightOp.stkSize; i++)
        {
        leftOp << rightOp.stkArray[i] << " ";
        }
return leftOp;
}
