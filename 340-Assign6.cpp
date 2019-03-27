#include "binTreeNode.h"
#include "/home/onyuksel/courses/340/common/340.h"

#ifndef BINTREE_H
#define BINTREE_H

/***************************
PROGRAM: binTree.h
PROGRAMMER: 
Date Due: March 19 2013
***************************/

template <class T> class binTree {
public:
 binTree ( ); // default constructor
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
Function: inorder

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
Function: preorder

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
Function: postorder

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
#endif

#include "/home/onyuksel/courses/340/common/340.h"

#ifndef BINTREENODE_H
#define BINTREENODE_H

/***************************
PROGRAM: binTreeNode.h
PROGRAMMER: 
Date Due: March 19 2013
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

#include "/home/onyuksel/courses/340/common/340.h"
#include "binTree.h"
#include "binTreeNode.h"

#ifndef PROG6_H
#define PROG6_H

/****************************
PROGRAM: prog6.h
PROGRAMMER:
Date Due: March 19 2013
****************************/

template <class T> void print(T&);
template <class T> void increase(T&);
template <class T> void decrease(T&);
template <class T> void isEmpty(const binTree <T>&);
template <class T> void header(const binTree <T>&);
template <class T> void inOrder(binTree <T>&, const string&);
template <class T> void preOrder(binTree <T>&, const string&);
template <class T> void postOrder(binTree <T>&, const string&);

const vector <int> A { 1, -2, 3, -4, 5, -6, 7, -8, 9, -10, 11, -12, 13, -14, 15};
const vector <float> B { 0.5, 1.75, -3, 4.25, 5.50, -6.75, 8, 9.25, -10.5};
const vector <string> C { "This", "is", "a", "list", "of", "string", "objects."};
/***************************************************************
Function: print

Use: prints out the object

Arguments: T&

Returns: void
***************************************************************/
template <class T>
void print(T& unit)
{
        cout << unit << " ";
}
/***************************************************************
Function: increase

Use: increased the value of the argument

Arguments: T&

Returns: void
***************************************************************/
template <class T>
void increase(T& unit)
{
        unit++; // increase by 1
}
/***************************************************************
Function: decrease

Use: decrease the value of the argument

Arguments: T&

Returns: void
***************************************************************/
template <class T>
void decrease(T& unit)
{
        unit--; // decrease by 1
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
        if(unit.empty() != true)        // tree is not empty
        {
                cout << "   Number of nodes: " << unit.size() << endl;
                cout << "   Tree Height: " << unit.height() << endl;
        }
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
        cout << "Inorder traversal of " << tree_root << ":" << endl;
        bin_tree.inorder(print);        // call binTree inorder function
}
/***************************************************************
Function: preOrder

Use: the preorder traversal

Arguments: binTree<T>& const string&

Returns: void
***************************************************************/
template <class T>
void preOrder(binTree<T>& bin_tree, const string& tree_root)
{
        cout << "Preorder traversal of " << tree_root << ":" << endl;
        bin_tree.preorder(print);       // call binTree preorder function
}
/***************************************************************
Function: postOrder

Use: the postorder traversal

Arguments: binTree<T>& const string&

Returns: void
***************************************************************/
template <class T>
void postOrder(binTree<T>& bin_tree, const string& tree_root)
{
        cout << "Postorder traversal of " << tree_root << ":" << endl;
        bin_tree.postorder(print);      // call binTree postorder function
}

#endif

/***************************
PROGRAM: Assignment 6
PROGRAMMER: 
Date Due: March 19 2013
***************************/

#include "/home/onyuksel/courses/340/common/340.h"
#include "prog6.h"

int main()
{
        binTree<int> one;       // int tree created
        binTree<float> two;     // float tree created
        binTree<string> three;  // string tree created

        for(unsigned int i = 0; i < A.size(); i++)      // build first tree
        {
                one.insert(A[i]);
        }
        one.preorder(increase);
        cout << "Integer tree: ";
        header(one);
        cout << endl << endl;

        inOrder(one, "Integer tree");
        cout << endl;
        preOrder(one, "Integer tree");
        cout << endl;
        postOrder(one, "Integer tree");
        cout << endl;

        for(unsigned int i = 0; i < B.size(); i++)      // build the second tree
        {
                two.insert(B[i]);
        }
        two.preorder(decrease);
        cout << "Float tree: ";
        header(two);
        cout << endl << endl;

        inOrder(two, "Float tree");
        cout << endl;
        preOrder(two, "Float tree");
        cout << endl;
        postOrder(two, "Float tree");
        cout << endl;

        for(unsigned int i = 0; i < C.size(); i ++)     // build the third tree
        {
                three.insert(C[i]);
        }
        cout << "String tree: ";
        header(three);
        cout << endl << endl;

        inOrder(three, "String tree");
        cout << endl;
        preOrder(three, "String tree");
        cout << endl;
        postOrder(three, "String tree");

        return 0;
}
