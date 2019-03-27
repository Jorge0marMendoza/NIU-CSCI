#ifndef DEQUE_H
#define DEQUE_H

#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <cstdlib>
#include <stdexcept>

using std::ostream;
using std::cout;
using std::cin;
using std::endl;
using std::out_of_range;


//*****************************************************************
// FILE:      Deque.h
// AUTHOR:    
// LOGON ID:  
// DUE DATE:  November 28 2012
//
// PURPOSE:   Contains the declaration for the Node and Deque class.
//*****************************************************************

template <class T>
struct Node
{
T data;
Node<T>* next;
Node<T>* prev;
Node(const T& = T(), Node<T>* next = NULL, Node<T>* prev = NULL);
};

// Method definitions for the Node class

// Forward declaration of the Deque template class
template <class T>
class Deque;

// Forward declaration of the operator<< template function
template <class T>
std::ostream& operator<<(std::ostream&, const Deque<T>&);

template <class T>
class Deque
{
friend std::ostream& operator<< <>(std::ostream&, const Deque<T>&);
private:
Node<T>* dHead;
Node<T>* dTail;
int dSize;
void copyList(const Deque<T>&);

public:
Deque();
~Deque();
Deque(const Deque<T>&);
const Deque<T>& operator=(const Deque<T>&);
void clear();
int size() const;
bool empty() const;
const T& front() const;
T& front();
const T& back() const;
T& back();
void push_front(const T&);
void push_back(const T&);
void pop_front();
void pop_back();
};

/***************************************************************
Class and Struct method declarations
***************************************************************/
/***************************************************************
Constructor1: Node<T>

Use: copy the argument into the queue code and set the node's
     pointer to NULL.

Arguments: const reference template parameter

Returns: None

Notes: None
***************************************************************/
template <class T>
Node<T>::Node(const T& newData, Node<T>* newNext, Node<T>* newPrev)
{
data = newData;
next = newNext;
prev = newPrev;
}
/***************************************************************
Constructor1: Deque

Use: sets both pointer data members to null.

Arguments: None

Returns: None

Notes: None
***************************************************************/
template <class T>
Deque<T>::Deque()
{
dHead = NULL;
dTail = NULL;
dSize = 0;
}
/***************************************************************
Destructor: ~Deque

Use: calls the clear method

Arguments: None

Returns: None

Notes: None
***************************************************************/
template <class T>
Deque<T>::~Deque()
{
clear();
}
/***************************************************************
Constructor2: (Copy) Deque

Use: makes a copy of the linked list

Arguments: None

Returns: None

Notes: None
***************************************************************/
template <class T>
Deque<T>::Deque(const Deque<T>& dequeToCopy)
{
dHead = NULL;
dTail = NULL;
dSize = 0;
copyList(dequeToCopy);
}
/***************************************************************
Method: Operator=

Use: overloaded to ...

Arguments: const Deque<T>&

Returns: const

Notes: None
***************************************************************/
template <class T>
const Deque<T>& Deque<T>::operator=(const Deque<T>& rightOp)
{
        if (this != &rightOp)
        {
        clear();
        copyList(rightOp);
        }
return *this;
}
/***************************************************************
Function: Operator<<

Use: sends an entire Queue to the standard output

Arguments: const Queue&

Returns: None

Notes: None
***************************************************************/
template <class T>
std::ostream& operator<<(std::ostream& leftOp, const Deque<T>& rightOp)
{
Node<T>* ptr;
        for (ptr = rightOp.dHead; ptr != NULL; ptr = ptr->next)
        {
        leftOp << ptr->data << ' ';
        }
return leftOp;
}
/***************************************************************
Method: clear

Use: sets the deque back to the empty state.

Arguments: None

Returns: None

Notes: None
***************************************************************/
template <class T>
void Deque<T>::clear()
{
        while(dSize != 0)
        {
        pop_front();
        }
}
/***************************************************************
Method: size

Use: returns the size of the deque

Arguments: None/const

Returns: int

Notes: None
***************************************************************/
template <class T>
int Deque<T>::size() const
{
return dSize;
}
/***************************************************************
Method: empty

Use: tests if the deque is empty

Arguments: None/const

Returns: bool

Notes: None
***************************************************************/
template <class T>
bool Deque<T>::empty() const
{
        if(dSize == 0)
        {
        return true;
        }
        else
        {
        return false;
        }
}
/***************************************************************
Method: front

Use: returns data stored in the front of the deque

Arguments: None

Returns: const T&

Notes: None
***************************************************************/
template <class T>
const T& Deque<T>::front() const
{
        if(dSize == 0)
        {
        throw out_of_range ("Deque underflow on front()");
        }
return dHead->data;
}
/***************************************************************
Method: front

Use: returns data stored in the front of the deque

Arguments: None

Returns: T&

Notes: None
***************************************************************/
template <class T>
T& Deque<T>::front()
{
        if(dSize == 0)
        {
        throw out_of_range ("Deque underflow on front()");
        }
return dHead->data;
}
/***************************************************************
Method: back

Use: returns data stored at back of deque

Arguments: None

Returns: const T&

Notes: None
***************************************************************/
template <class T>
const T& Deque<T>::back() const
{
        if(dSize == 0)
        {
        throw out_of_range ("Deque underflow on back()");
        }
return dTail->data;
}
/***************************************************************
Method: back

Use: returns data stored at back of deque

Arguments: None

Returns: T&

Notes: None
***************************************************************/
template <class T>
T& Deque<T>::back()
{
        if(dSize == 0)
        {
        throw out_of_range ("Deque underflow on back()");
        }
return dTail->data;
}
/***************************************************************
Method: push_front

Use: inserts item at the front of the deque

Arguments: const T&

Returns: None

Notes: None
***************************************************************/
template <class T>
void Deque<T>::push_front(const T& item)
{
Node<T>* newNode = new Node<T>(item);
        if(dSize == 0)
        {
        newNode ->next = dHead;
        dTail = newNode;
        dHead = newNode;
        }
        else
        {
        newNode->next = dHead;
        dHead->prev = newNode;
        dHead = newNode;
        }
dSize++;
}
/***************************************************************
Method: push_back

Use: inserts item at the back of the deque

Arguments: const T&

Returns: None

Notes: None
***************************************************************/
template <class T>
void Deque<T>::push_back(const T& item)
{
Node<T>* newNode = new Node<T>(item);
        if(dSize == 0)
        {
        newNode->prev = dTail;
        dHead = newNode;
        dTail = newNode;
        }
        else
        {
        newNode->prev = dTail;
        dTail->next = newNode;
        dTail = newNode;
        }
dSize++;
}
/***************************************************************
Method: pop_front

Use: deletes the item at the front of the deque

Arguments: None

Returns: None

Returns: None

Notes: None
***************************************************************/
template <class T>
void Deque<T>::pop_front()
{
        if(dSize == 0)
        {
        throw out_of_range ("Deque underflow on pop_front()");
        }
        else if(dSize == 1)
        {
        // Remove first node in list for one item
        Node<T>* delNode = dHead;
        dHead = delNode->next;
        dTail = NULL;
        delete delNode;
        }
        else
        {
        // Remove fist node in list for more than one item
        Node<T>* delNode = dHead;
        dHead = delNode->next;
        dHead->prev = NULL;
        delete delNode;
        }
dSize--;
// If queue now empty, both pointers should be NULL
        if(dHead == NULL)
        {
        dTail = NULL;
        }
}
/***************************************************************
Method: pop_back

Use: deletes the item at the rear of the deque

Arguments: None

Returns: None

Notes: None
***************************************************************/
template <class T>
void Deque<T>::pop_back()
{
        if(dSize == 0)
        {
        throw out_of_range ("Deque underflow on pop_back()");
        }
        else if(dSize == 1)
        {
        // Remove last node in list for one item
        Node<T>* delNode = dTail;
        dTail = delNode->prev;
        dHead = NULL;
        delete delNode;
        }
        else
        {
        // Remove last node in list for more than one item
        Node<T>* delNode = dTail;
        dTail = delNode->prev;
        dTail->next = NULL;
        delete delNode;
        }
dSize--;
// If queue now empty, both pointers should be NULL
        if(dTail == NULL)
        {
        dHead = NULL;
        }
}
/***************************************************************
Method: copyList

Use: copies one queue to another

Arguments: const Deque&

Returns: None

Notes: None
***************************************************************/
template <class T>
void Deque<T>::copyList(const Deque& dequeToCopy)
{
Node<T>* ptr;
        for(ptr = dequeToCopy.dHead; ptr != '\0'; ptr = ptr->next)
        {
        push_back(ptr->data);
        }
}

#endif
