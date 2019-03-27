/*************************
PROGRAMMER: 
PROGRAM: Assignment 3
DATE DUE: Feburary 7 2013
**************************/

#include "/home/onyuksel/courses/340/progs/13s/p3/prog3.h"
#include "/home/onyuksel/courses/340/common/340.h"

void sieve(set <int>&, int);
void print_primes (const set <int>&);

int main()
{
int upper_limit;        // initialize variables
set <int> s;

cout << "Enter Upper Limit: ";  // prompts user for the upper limit
cin >> upper_limit;
cout << endl;

sieve(s, upper_limit);  // pass set into sieve to find primes
print_primes(s);        // pass set into function to print output

return 0;
}
/***************************************************************
Function: sieve

Use: removes all non primes numbers from the integer set.

Arguments: set <int>&, int

Returns: void
***************************************************************/
void sieve(set <int>& s, int n)
{
        for(int i = 0; i < n + 1; i++)  // inserts "upper_limit" integers into the set
        {
        s.insert(i);
        }
        for(int m = 2; m < n; m++)      // loops through set
        {
                for(int k = m*m; k <= n; k+= m) // removes all non-primes form the set
                {
                s.erase(k);
                }
        }
}
/***************************************************************
Function: print_primes

Use: prints all elements in the integer set, only NO_ITEMS per
     line and ITEM_W space for each interger.

Arguments: const set <int>&

Returns: void
***************************************************************/
void print_primes(const set <int>& s)
{
int line_end = 0;       // initialze counter
set <int>::iterator itr;
        for(itr = s.begin(); itr != s.end(); itr++)     // loops through set
        {
        line_end++;     // increase in counter for each element
        cout << setw(ITEM_W) << *itr;	// prints each element in set
                if(line_end == NO_ITEMS)
                {
                cout << "/n";   // creates new line every NO_ITEMS
                line_end = 0;   // reset the line counter
                }
        }
}
