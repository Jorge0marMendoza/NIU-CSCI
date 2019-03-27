/*******************************
PROGRAMMER: 
PROGRAM: Assignment 2 (prog2.cc)
Date Due: January 30th 2013
*******************************/

#include "/home/onyuksel/courses/340/common/340.h"
#include "/home/onyuksel/courses/340/progs/13s/p2/prog2.h"

int main()
{
vector<int> v1(ARR_SIZE);       // Define two empty vectors
vector<int> v2(TEST_ARR_SIZE);

Vectors(v1, v2, SEED1, SEED2);  // Pass vectors and seed value as arguments to subroutine

cout << "Unsorted Values in Vector 1:" << endl;
printVector(v1);        // prints the first vector

sortVector(v1);         // sorts the vector
cout << endl << endl;   // space between sorted and unsorted Values

cout << "Sorted Values in Vector 1:" << endl;
printVector(v1);
cout << endl << endl;

cout << "Unsorted Values in Vector 2:" << endl;
printVector(v2);        // prints the second vector
cout << endl << endl;

cout << "Search Results" << endl;
cout << "Linear Search: " << endl;
search (v1, v2, linearSearch);  // linear search of the two vectors
cout << endl;
cout << "Binary Search: " << endl;
search (v1, v2, binarySearch);  // binary search of the two vectors

return 0;
}
