#ifndef MYSTRING_H
#define MYSTRING_H

using std::ostream;
using std::out_of_range;

//*****************************************************************
// FILE:      MyString.h
// AUTHOR:    
// LOGON ID:  
// DUE DATE:  October 18 2012
//
// PURPOSE:   Contains the declaration for the MyString class.
//*****************************************************************

class MyString
{
friend ostream& operator<<(ostream& leftOp, const MyString& rightOp);
friend bool operator==(const char* leftOp, const MyString& rightOp);
friend MyString operator+(const char* leftOp, const MyString& rightOp);
private:        //private data members
char* strArray;
int strSize;
int strcap;

public:         //method prototypes
MyString();
MyString(const char* s);
MyString(const MyString& s);
bool operator==(const MyString& rightOp) const;
bool operator==(const char* rightOp) const;
char operator[](int sub) const;
char& operator[](int sub);
const char* c_str() const;
bool empty() const;
int size() const;
void clear();
int capacity() const;
~MyString();
const MyString& operator=(const MyString& rightOp);
const MyString& operator=(const char* rightOp);
MyString operator+(const MyString& rightOp) const;
MyString operator+(const char* rightOp) const;
char at(int sub) const throw(out_of_range);
char& at(int sub) throw(out_of_range);
};

#endif

#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <cstdlib>
#include <stdexcept>
#include "MyString.h"

using std::cout;
using std::cin;
using std::endl;
using std::out_of_range;

/*********************************************************************
PROGRAM:    MyString.cpp
PROGRAMMER: 
LOGON ID:   
DUE DATE:   October 25 2012

FUNCTION:   This program creates and store all the methods used in
            the MyString class
*********************************************************************/

/***************************************************************
Constructor1: MyString

Use: sets all elements of the array to null.

Arguments: None

Returns: None

Notes: None
***************************************************************/
MyString::MyString()
{
strcap = 1;
strArray = new char[strcap];
strcpy(strArray, "");
strSize = 0;
}
/***************************************************************
Constructor2: MyString

Use: copies the C strings into the array.

Arguments: const char*

Returns: None

Notes: None
***************************************************************/
MyString::MyString(const char* s)
{
strSize = strlen(s);
strcap = strSize + 1;
strArray = new char[strcap];
strcpy(strArray, s);
}
/***************************************************************
Constructor3: MyString

Use: initalizes a new object to the existing string object.

Arguments: const

Returns: None

Notes: None
***************************************************************/
MyString::MyString(const MyString& s)
{
//#1
strSize = s.strSize;
strcap = s.strcap;
//#2
strArray = new char [strcap];
//#3
strcpy(strArray, s.strArray);
}
/***************************************************************
Method: Operator==1

Use: test the C string in the array agianst the C sting in the
     right Op.

Arguments: const

Returns: bool

Notes: None
***************************************************************/
bool MyString::operator==(const MyString& rightOp) const
{
        if(strcmp(strArray, rightOp.strArray) == 0)
        {
        return true;
        }

        else
        {
        return false;
        }
}
/***************************************************************
Method: Operator==2

Use: tests the C string in the array against the right Op.

Arguments: const char*

Returns: bool

Notes: None
***************************************************************/
bool MyString::operator==(const char* rightOp) const
{
        if(strcmp(strArray, rightOp) == 0)
        {
        return true;
        }

        else
        {
        return false;
        }
}
/***************************************************************
Method: Operator[]1

Use: returns the variable "sub" of the string array.

Arguments: int const

Returns: char

Notes: None
***************************************************************/
char MyString::operator[](int sub) const
{
return strArray[sub];
}
/***************************************************************
Method: Operator[]2

Use: returns the variable "sub" of the string array.

Arguments: int

Returns: char&

Notes: None
***************************************************************/
char& MyString::operator[](int sub)
{
return strArray[sub];
}
/***************************************************************
Method: c_str

Use: gives the name of the string array for use as a pointer.

Arguments: const

Returns: const char*

Notes: None
***************************************************************/
const char* MyString::c_str() const
{
return strArray;
}
/***************************************************************
Method: empty

Use: tells if the string size is 0

Arguments: const

Returns: bool

Notes: None
***************************************************************/
bool MyString::empty() const
{
        if(strSize == 0)
        {
        return true;
        }

        else
        {
        return false;
        }
}
/***************************************************************
Method: size

Use: returns the size of the string.

Arguments: const

Returns: int

Notes: None
***************************************************************/
int MyString::size() const
{
return strSize;
}
/***************************************************************
Method: clear

Use: nulls the c string and sets the array size to 0.

Arguments: None

Returns: void

Notes: None
***************************************************************/
void MyString::clear()
{
strcpy(strArray, "");
strSize = 0;
}
/***************************************************************
Method: capacity

Use: returns the capacity of the string.

Arguments: const

Returns: int

Notes: None
***************************************************************/
int MyString::capacity() const
{
return strcap;
}
/***************************************************************
Method: Operator=1

Use: assigns one object of the class to another.

Arguments: const

Returns: const

Notes: None
***************************************************************/
const MyString& MyString::operator=(const MyString& rightOp)
{
        if(this != &rightOp)
        {
        strSize = rightOp.strSize;
                if(strcap < strSize + 1)
                {
                delete[] strArray;
                strcap = rightOp.strcap;
                strArray = new char [strcap];
                }
        strcpy(strArray, rightOp.strArray);
        }
return *this;
}
/***************************************************************
Method: Operator=2

Use: assigns one object of the class to another.

Arguments: const

Returns: const

Notes: None
***************************************************************/
const MyString& MyString::operator=(const char* rightOp)
{
strSize = strlen(rightOp);
        if(strcap < strSize + 1)
        {
        delete[] strArray;
        strcap = strSize + 1;
        strArray = new char [strcap];
        }
        strcpy(strArray, rightOp);
return *this;
}
/***************************************************************
Destructor: ~MyString

Use: deletes the string arrays.

Arguments: None

Returns: None

Notes: None
***************************************************************/
MyString::~MyString()
{
delete[] strArray;
}
/***************************************************************
Method: Operator+1

Use: concatenate the C string rightOp onto the end of the string

Arguments: const

Returns: None

Notes: None
***************************************************************/
MyString MyString::operator+(const MyString& rightOp) const
{
MyString result;
result.strSize = strSize + rightOp.size();
delete[] result.strArray;
result.strcap = result.strSize + 1;
result.strArray = new char[result.strcap];
strcpy(result.strArray, strArray);
strcat(result.strArray, rightOp.strArray);
return result;
}
/***************************************************************
Method: Operator+2

Use: concatenate the C string rightOp onto the end of the string

Arguments: const

Returns: None

Notes: None
***************************************************************/
MyString MyString::operator+(const char* rightOp) const
{
MyString result;
result.strSize = strSize + strlen(rightOp);
delete[] result.strArray;
result.strcap = result.strSize + 1;
result.strArray = new char[result.strcap];
strcpy(result.strArray, strArray);
strcat(result.strArray, rightOp);
return result;
}
/***************************************************************
Method: at1

Use: throws an exception if sub is less than 0 or greater than
     or equal to the string size.

Arguments: int const

Returns: char

Notes: None
***************************************************************/
char MyString::at(int sub) const throw(out_of_range)
{
        if (sub < 0 || sub >= strSize)
        {
                throw out_of_range ("Subscript out of range");
        }
        return strArray[sub];
}
/***************************************************************
Method: at2

Use: throws an exception if sub is less than 0 or greater than
     or equal to the string size.

Arguments: int const

Returns: char&

Notes: None
***************************************************************/
char& MyString::at(int sub) throw(out_of_range)
{
        if (sub < 0 || sub >= strSize)
        {
                throw out_of_range ("Subscript out of range");
        }
        return strArray[sub];
}
/***************************************************************
Function: Operator<<

Use: prints the C string stored in the right Op.

Arguments: const

Returns: None

Notes: None
***************************************************************/
ostream& operator<<(ostream& leftOp, const MyString& rightOp)
{
leftOp << rightOp.strArray;

return leftOp;
}
/***************************************************************
Function: Operator==

Use: test the C string in the left Op is equal to the string
     passed in the right Op.

Arguments: const char*

Returns: bool

Notes: None
***************************************************************/
bool operator==(const char* leftOp, const MyString& rightOp)
{
        if(strcmp(leftOp, rightOp.strArray) == 0)
        {
        return true;
        }

        else
        {
        return false;
        }
}
/***************************************************************
Function: Operator+

Use: concatenate the string stored in the object rightOp onto the
     the end of the string leftOp.

Arguments: const char*

Returns: None

Notes: None
***************************************************************/
MyString operator+(const char* leftOp, const MyString& rightOp)
{
MyString result;
result.strSize = strlen(leftOp) + rightOp.size();
delete[] result.strArray;
result.strcap = result.strSize + 1;
result.strArray = new char[result.strcap];
strcpy(result.strArray, leftOp);
strcat(result.strArray, rightOp.strArray);
return result;
}

