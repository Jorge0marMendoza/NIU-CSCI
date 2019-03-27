#include "/home/onyuksel/courses/340/common/340.h"

#ifndef BINTREENODE_H
#define BINTREENODE_H

/***************************
PROGRAM: binTreeNode.h
PROGRAMMER: 
Date Due: March 27 2013
***************************/

template <class T> class binTree;       // forward declaration

template <class T> class binTreeNode{
friend class binTree<T>;        // class binTree is friend
public:
        // default constructor
 binTreeNode(const T& = T(), binTreeNode <T>* = NULL, binTreeNode <T>* = NULL);
private:
 T data;        // data component
 binTreeNode <T> *left, *right; // left and right links
};

/***************************************************************
Constructor: binTreeNode

Use: initailzes the pointers and T data

Arguments: const T&, binTreeNode <T>*

Returns: None
***************************************************************/
template <class T>
binTreeNode<T>::binTreeNode(const T& datainfo, binTreeNode <T>* lchild, binTreeNode <T>* rchild)
{
        data = datainfo;
        left = lchild;
        right = rchild;
}

#endif

#include "binTreeNode.h"
#include "/home/onyuksel/courses/340/common/340.h"

#ifndef BINTREE_H
#define BINTREE_H

/***************************
PROGRAM: binTree.h
PROGRAMMER: 
Date Due: March 27 2013
***************************/

template <class T> class binTree {
friend class binTreeNode<T>;        // class binTreeNode is friend
public:
 binTree ( ); // default constructor
 binTree ( const binTree < T >& ); // copy constructor
 binTree < T >& operator = ( const binTree < T >& ); // assignment operator
 virtual ~binTree ( ); // destructor
 void clear ( ); // destroys tree
 bool empty ( ) const; // checks if tree empty
 int size ( ) const; // returns no of nodes
 int height ( ) const; // returns height of tree
 virtual void insert ( const T& ); // inserts a node in shortest subtree
 void inorder ( void ( * ) ( T& ) ); // inorder traversal of tree
 void preorder ( void ( * ) ( T& ) ); // preorder traversal of tree
 void postorder ( void ( * ) ( T& ) ); // postorder traversal of tree
protected:
 binTreeNode < T >* root; // root of tree
private:
 int size ( binTreeNode < T >* ) const; // private version of size ( )
 int height ( binTreeNode < T >* ) const; // private version of height ( )
 void insert ( binTreeNode < T >*&, const T& ); // private version of insert ( )
 void inorder ( binTreeNode < T >*, void ( * ) ( T& ) ); // private version of inorder ( )
 void preorder ( binTreeNode < T >*, void ( * ) ( T& ) ); // private version of preorder ( )
 void postorder ( binTreeNode < T >*, void ( * ) ( T& ) );// private version of postorder ( )
 virtual ~binTree ( ); // destructor
 void clear ( ); // destroys tree
};

/***************************************************************
Constructor: binTree

Use: builds the binary tree.

Arguments: None

Returns: None
***************************************************************/
template <class T>
binTree<T>::binTree()
{
        root = NULL;
}
/***************************************************************
Copy Constructor: binTree

Use: makes a copy of the current tree

Arguments: const binTree<T>&

Returns: None
***************************************************************/
template <class T>
binTree<T>::binTree(const binTree<T>& tree_node)
{
        root = copy(tree_node.root);
}
/***************************************************************
Function: operatior=

Use: assigns each node of the first tree to the repective node
     in the clone tree

Arguments: const binTree<T>&

Returns: binTree&
***************************************************************/
template <class T>
binTree<T>& binTree<T>::operator=(const binTree<T>& tree_node)
{
        if( this != &tree_node)
        {
                clear();

                this->root = copy(tree_node.root);

        }
        return *this;
}
/***************************************************************
Destructor: ~binTree

Use: free the allocated memory for a binary tree

Arguments: None

Returns: virtual
***************************************************************/
template <class T>
binTree<T>::~binTree()
{
        clear();
}
/***************************************************************
Function: clear

Use: destroys the binary tree.

Arguments: None

Returns: void
***************************************************************/
template <class T>
void binTree<T>::clear()
{
        clear(root);    // private version of clear function
}
/***************************************************************
Function: empty

Use: tests if the tree is empty and tells user if true or false

Arguments: const

Returns: bool
***************************************************************/
template <class T>
bool binTree<T>::empty() const
{
        if(root == NULL)        // tree is empty
        {
                return true;
        }
        else
        {
                return false;
        }
}
/***************************************************************
Function: size

Use: find the number of nodes in the tree

Arguments: const

Returns: int
***************************************************************/
template <class T>
int binTree<T>::size() const
{
        if(root != NULL)        // test if tree exists
        {
                int s = 1 + size(root->left) + size(root->right);
                // counts left child and right child and adds the root
                return s;
        }
        else
        {
                return 0;
        }
}
/***************************************************************
Funtion: height

Use: finds the height of the tree

Arguments: const

Returns: int
***************************************************************/
template <class T>
int binTree<T>::height() const
{
        if(root != NULL)        // test if tree exists
        {
                int h = 1 + height(root->left);
                // counts left child and adds the root
                return h;
        }
        else
        {
                return 0;
        }
}
/***************************************************************
Function: insert

Use: inserts a node by calling the private method

Arguments: const T&

Returns: void
***************************************************************/
template <class T>
void binTree<T>::insert(const T& x)
{
        insert(root, x);
}
/***************************************************************
Function: inorder

Use: calls the function print for the private inorder function

Arguments: void(*)(T&)

Returns: void
***************************************************************/
template <class T>
void binTree<T>::inorder(void(* ptr)(T&))
{
        inorder(root, ptr);
}
/***************************************************************
Function: preorder

Use: calls the function print for the private preorder function

Arguments: void(*)(T&)

Returns: void
***************************************************************/
template <class T>
void binTree<T>::preorder(void(* ptr)(T&))
{
        preorder(root, ptr);
}
/***************************************************************
Function: postorder

Use: calls the function print for the private postorder function

Arguments: void(*)(T&)

Returns: void
***************************************************************/
template <class T>
void binTree<T>::postorder(void(* ptr)(T&))
{
        postorder(root, ptr);
}
/***************************************************************
Private Function: size

Use: private version of size()

Arguments: binTreeNode<T>* const

Returns: int
***************************************************************/
template <class T>
int binTree<T>::size(binTreeNode<T>* inNode) const
{
        if(inNode == NULL)
        {
                return 0;
        }
        else
        {
                return size(inNode->left) + size(inNode->right) + 1;
        }
}
/***************************************************************
Private Function: height

Use: private version of height()

Arguments: binTreeNode<T>* const

Returns: int
***************************************************************/
template <class T>
int binTree<T>::height(binTreeNode<T>* inNode) const
{
        if(inNode == NULL)
        {
                return 0;
        }
        else
        {
                return max(height(inNode->left),height(inNode->right)) + 1;
        }
}
/***************************************************************
Private Function: insert

Use: private version of insert()

Arguments: binTreeNode<T>*& const t&

Returns: void
***************************************************************/
template <class T>
void binTree<T>::insert(binTreeNode<T>*& tree_root, const T& x)
{
        if(tree_root != NULL)
        {
                if(height(tree_root->left) > height(tree_root->right))  // right subtree is smaller then left
                {
                        insert(tree_root->right, x);    // inset x into right subtree
                }
                else    // insert into left subtree
                {
                        insert(tree_root->left, x);
                }
        }
        else
        {
                tree_root = new binTreeNode<T>(x);      // make x the root
        }
}
/***************************************************************
Private Function: inorder

Use: calls a function pointer to complete inorder traversal

Arguments: binTree<T>*, void(*)(T&)

Returns: void
***************************************************************/
template <class T>
void binTree<T>::inorder(binTreeNode<T>* child, void (* ptr)(T&))
{
        if(child != NULL)
        {
                inorder(child->left, ptr);
                ptr(child->data);
                inorder(child->right, ptr);
        }
}
/***************************************************************
Private Function: preorder

Use: calls a functions pointer to complete preorder traversal

Arguments: binTree<T>* void(*)(T&)

Returns: void
***************************************************************/
template <class T>
void binTree<T>::preorder(binTreeNode<T>* child, void (* ptr)(T&))
{
        if(child != NULL)
        {
                ptr(child->data);
                preorder(child->left, ptr);
                preorder(child->right, ptr);
        }
}
/**************************************************************
Private Function: postorder

Use: calls a functions pointer to complete postorder traversal

Arguments: binTree<T>* void(*)(T&)

Returns: void
***************************************************************/
template <class T>
void binTree<T>::postorder(binTreeNode<T>* child, void (* ptr)(T&))
{
        if(child != NULL)
        {
                postorder(child->left, ptr);
                postorder(child->right, ptr);
                ptr(child->data);
        }
}
/***************************************************************
Private Function: clear

Use: private version of clear()

Arguments: binTreeNode<T>*&

Returns: void
***************************************************************/
template <class T>
void binTree<T>::clear(binTreeNode<T>*& tree)
{
        if( tree != NULL )
        {
        clear( tree->left );
        clear ( tree->right);
        delete tree;    // deletes the argument value
        tree = NULL;
        }
}
/***************************************************************
Private Function: copy

Use: creates a clone of the binary tree

Arguments: const binTreeNode<T>*&

Returns: binTreeNode<T>*
***************************************************************/
template <class T>
binTreeNode<T>* binTree<T>::copy(const binTreeNode<T>* tree)
{
        if(tree == NULL)
        {
                root = NULL;
                return root;
        }
        else
        {
                binTreeNode<T>* temp = new binTreeNode<T> (tree->data);
                temp->left = copy(tree->left);
                temp->right = copy(tree->right);
                return temp;
        }
}

#endif

/***************************
PROGRAM: Assignment 7
PROGRAMMER:
DATE DUE: March 27 2013
***************************/

#include "binTree.h"
#include "/home/onyuksel/courses/340/progs/13s/p7/prog7.h"

const vector < int > A { 1, -2, 3, -4, 5, -6, 7, -8, 9, -10, 11, -12,
        13, -14, 15 };
const vector < float > B { 0.5, 1.75, -3, 4.25, 5.50, -6.75, 8, 9.25,
        -10.5 };
const vector < string > C { "This", "is", "a", "list", "of", "string",
        "objects." };

int main ( )
{
        binTree < int > first;
        for ( unsigned i = 0; i < A.size ( ); i++ )
                first.insert ( A [ i ] );
        first.inorder ( increase );

        cout << "first:"; header ( first );
        inOrder ( first, "first" ); cout << endl;

        binTree < int > second ( first );
        second.inorder ( decrease );

        first.clear ( );
        cout << "first:"; header ( first );
        cout << "second:"; header ( second );
        inOrder ( second, "second" ); cout << endl;

         binTree < float > third, fourth;
        for ( unsigned i = 0; i < B.size ( ); i++ )
                third.insert ( B [ i ] );

        cout << "third:"; header ( third );
        third.inorder ( increase );
        inOrder ( third, "third" ); cout << endl;

        fourth = third;
        cout << "fourth:"; header ( fourth );
        fourth.inorder ( decrease );
        inOrder ( fourth, "fourth" ); cout << endl;

        binTree < string > fifth;
        for ( unsigned i = 0; i < C.size ( ); i++ )
                fifth.insert ( C [ i ] );

        cout << "fifth:"; header ( fifth );
        binTree <string> sixth = fifth;
        cout << "sixth:"; header ( sixth );
        inOrder ( sixth, "sixth" );

        return 0;
}
/***************************************************************
Function: print

Use: prints out the object

Arguments: T&

Returns: void
***************************************************************/
template <class T>
void print(T& x)
{
        cout << x << " ";
}
/***************************************************************
Function: increase

Use: increased the value of the argument

Arguments: T&

Returns: void
***************************************************************/
template <class T>
void increase(T& x)
{
        x++;    // increase by 1
}
/***************************************************************
Function: decrease

Use: decreased the value of the argument

Arguments: T&

Returns: void
***************************************************************/
template <class T>
void decrease(T& x)
{
        x--;    // decrease by 1
}
/***************************************************************
Function: isEmpty

Use: tests if the tree is empty

Arguments: const binTree<T>&

Returns: void
***************************************************************/
template <class T>
void isEmpty(const binTree<T>& tree_data)
{
        if(tree_data.empty() == true)
        {
        cout << "The tree is empty." << endl;
        }
        else
        {
        cout << "The tree is not  empty." << endl;
        }
}
/***************************************************************
Function: header

Use: find the height and print the traversals of the tree.

Arguments: const binTree <T>&

Returns: void
***************************************************************/
template <class T>
void header(const binTree <T>& unit)
{
        isEmpty(unit);
//      if(unit.empty() != true)        // tree is not empty
//      {
        cout << "   Number of nodes: " << unit.size() << endl;
        cout << "   Tree Height: " << unit.height() << endl << endl;
//      }
}
/***************************************************************
Function: inOrder

Use: the inorder traversal

Arguments: binTree<T>& const string&

Returns: void
***************************************************************/
template <class T>
void inOrder(binTree<T>& bin_tree, const string& tree_root)
{
        cout << "Inorder traversal of " << tree_root << ":" << endl << "   ";
        bin_tree.inorder(print);        // call binTree inorder function
}
