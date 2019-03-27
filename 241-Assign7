#ifndef QUEUE_H
#define QUEUE_H

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
// FILE:      Queue.h
// AUTHOR:    
// LOGON ID:  
// DUE DATE:  November 20 2012
//
// PURPOSE:   Contains the declaration for the Node and Queue class.
//*****************************************************************

template <class T>
struct Node
{
T data;
Node<T>* next;
Node(const T& = T(), Node<T>* next = NULL);
};

// Forward declaration of the Queue template class
template <class T>
class Queue;

// Forward declaration of the operator<< template function
template <class T>
std::ostream& operator<<(std::ostream&, const Queue<T>&);

template <class T>
class Queue
{
friend std::ostream& operator<< <>(std::ostream& leftOp, const Queue& rightOp);
private:
Node<T>* qFront;
Node<T>* qRear;
int qSize;
void copyList(const Queue<T>&);

public:
Queue();
~Queue();
Queue(const Queue<T>&);
const Queue<T>& operator=(const Queue<T>&);
void clear();
int size() const;
bool empty() const;
T front() const;
T back() const;
void push(const T&);
void pop();
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
Node<T>::Node(const T& newData, Node<T>* newNext)
{
data = newData;
next = newNext;
}
/***************************************************************
Constructor1: Queue

Use: sets both pointer data members to null.

Arguments: None

Returns: None

Notes: None
***************************************************************/
template <class T>
Queue<T>::Queue()
{
qFront = NULL;
qRear = NULL;
qSize = 0;
}
/***************************************************************
Destructor: ~Queue

Use: calls the clear method

Arguments: None

Returns: None

Notes: None
***************************************************************/
template <class T>
Queue<T>::~Queue()
{
clear();
/***************************************************************
Constructor2: (Copy) Queue

Use: makes a copy of the linked list

Arguments: None

Returns: None

Notes: None
***************************************************************/
template <class T>
Queue<T>::Queue(const Queue<T>& queueToCopy)
{
qFront = NULL;
qRear = NULL;
qSize = 0;
copyList(queueToCopy);
}
/***************************************************************
Method: Operator=

Use: overloaded to ...

Arguments: const Queue<T>&

Returns: const

Notes: None
***************************************************************/
template <class T>
const Queue<T>& Queue<T>::operator=(const Queue<T>& rightOp)
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
ostream& operator<<(ostream& leftOp, const Queue<T>& rightOp)
{
Node<T>* ptr;
        for (ptr = rightOp.qFront; ptr != NULL; ptr = ptr->next)
        {
        leftOp << ptr->data << ' ';
        }
return leftOp;
}
/***************************************************************
Method: clear

Use: sets the queue back to the empty state.

Arguments: None

Returns: None

Notes: None
***************************************************************/
template <class T>
void Queue<T>::clear()
{
        while(qSize != 0)
        {
        pop();
        }
}
/***************************************************************
Method: size

Use: returns the size of the queue

Arguments: None/const

Returns: int

Notes: None
***************************************************************/
template <class T>
int Queue<T>::size() const
{
return qSize;
}
/***************************************************************
Method: empty

Use: tests if the queue is empty

Arguments: None/const

Returns: bool

Notes: None
***************************************************************/
template <class T>
bool Queue<T>::empty() const
{
        if(qSize == 0)  // could also test if front is NULL
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

Use: returns data stored in the front of the queue

Arguments: None

Returns: T

Notes: None
***************************************************************/
template <class T>
T Queue<T>::front() const
{
        if(qSize == 0)
        {
        throw out_of_range ("Queue underflow on front()");
        }
return qFront->data;
}
/***************************************************************
Method: back

Use: returns data stored at back of queue

Arguments: None

Returns: T

Notes: None
***************************************************************/
template <class T>
T Queue<T>::back() const
{
        if(qSize == 0)
        {
        throw out_of_range ("Queue underflow on back()");
        }
return qRear->data;
}
/***************************************************************
Method: push

Use: inserts item at rear of the queue

Arguments: const T&

Returns: None

Notes: None
***************************************************************/
template <class T>
void Queue<T>::push(const T& item)
{
Node<T>* newNode = new Node<T>(item);
        if(qSize == 0)
        {
        qFront = newNode;
        }
        else
        {
        qRear->next = newNode;
        }
qRear = newNode;
qSize++;
}
/***************************************************************
Method: pop

Use: removes the item at the front of the queue

Arguments: None

Returns: None

Notes: None
***************************************************************/
template <class T>
void Queue<T>::pop()
{
        if(qSize == 0)
        {
        throw out_of_range ("Queue underflow on pop()");
        }
// Remove first node in list
Node<T>* delNode = qFront;
qFront = qFront->next;
// If queue now empty, both pointers should be NULL
        if(qFront == '\0')
        {
        qRear = '\0';
        }
delete delNode;
qSize--;
}
/***************************************************************
Method: copyList

Use: copies one queue to another

Arguments: cons Queue&

Returns: None

Notes: None
***************************************************************/
template <class T>
void Queue<T>::copyList(const Queue& queueToCopy)
{
Node<T>* ptr;
        for(ptr = queueToCopy.qFront; ptr != '\0'; ptr = ptr->next)
        {
        push(ptr->data);
        }
}

#endif
