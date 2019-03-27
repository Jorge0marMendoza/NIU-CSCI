/******************************
PROGRAMMER: 
PROGRAM: Assignment 1
DATE DUE: 1/22/13
******************************/

#include "/home/onyuksel/courses/340/common/340.h"
#include "/home/onyuksel/courses/340/progs/13s/p1/prog1.h"

int main()
{
int arr[ARR_SIZE];      // initialize array
genRndNums(arr);      // call function to generate random numbers
sort(arr, arr + ARR_SIZE);      // sort the elements in ascending order
printArr(arr);        // call function to print array

return 0;
}

/****************************
Functions
****************************/
/***************************************************************
Function: genRndNums

Use: generates ARR_SIZE ints & puts them in the array.

Arguments: int

Returns: void
***************************************************************/
void genRndNums(int arr[])
{
srand(SEED);    // initialize the RNG
        for(int i = 0; i < ARR_SIZE; i++)
        {
        arr[i] = rand() % (HIGH - LOW + 1) + LOW;       // generates random numbers
        }
}
/***************************************************************
Function: printArr

Use: displays the contents of the array

Arguments: int

Returns: void
***************************************************************/
void printArr(int arr[])
{
int line_end = 0;
        for(int i = 0; i < ARR_SIZE; i++)
        {
        cout << arr[i] << setw(ITEM_W);
        line_end++;
                if (line_end == NO_ITEMS)       // tests for where to end each line
                {
                cout << "\n";   // make a new line
                line_end = 0;   // reset the count
                }
        }
}
