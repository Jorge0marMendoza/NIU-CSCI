#include "/home/onyuksel/courses/340/progs/13s/p9/prog9.h"

/***************************
PROGRAM: Prog9.cc
PROGRAMMER: 
***************************/

int main ( )
{
        vector < int >    v1;   // heap of integers
        vector < float >  v2;   // heap of floating-pt nums
        vector < string > v3;   // heap of strings

        // print header message
        cout << "\t\t\t*** CSCI 340: Program 9 - Output ***\n\n";

        // first heap

        cout << "first heap - ascending order:\n\n";
        get_list ( v1, D1 );
        construct_heap ( v1, less < int > ( ) );
        print_list < int, INT_SZ, INT_LN > print1 ( v1.size ( ) );
        for_each ( v1.begin ( ), v1.end ( ), print1 );
        cout << endl << endl;

        cout << "first heap - descending order:\n\n";
        get_list ( v1, D1 );
        construct_heap ( v1, greater < int > ( ) );
        for_each ( v1.begin ( ), v1.end ( ), print1 );
        cout << endl << endl;

        cout << "first heap - ascending order with absolute values:\n\n";
        get_list ( v1, D1 );
        construct_heap ( v1, abs_less < int > ( ) );
        for_each ( v1.begin ( ), v1.end ( ), print1 );
        cout << endl << endl;

        // second heap

        cout << "second heap - ascending order:\n\n";
        get_list ( v2, D2 );
        construct_heap ( v2, less < float > ( ) );
        print_list < float, FLT_SZ, FLT_LN > print2 ( v2.size ( ) );
        for_each ( v2.begin ( ), v2.end ( ), print2 );
        cout << endl << endl;

        cout << "second heap - descending order:\n\n";
        get_list ( v2, D2 );
        construct_heap ( v2, greater < float > ( ) );
        for_each ( v2.begin ( ), v2.end ( ), print2 );
        cout << endl << endl;

        cout << "second heap - ascending order with absolute values:\n\n";
        get_list ( v2, D2 );
        construct_heap ( v2, abs_less < float > ( ) );
        for_each ( v2.begin ( ), v2.end ( ), print2 );
        cout << endl << endl;

        // third heap

        cout << "third heap - ascending order:\n\n";
        get_list ( v3, D3 );
        construct_heap ( v3, less < string > ( ) );
        print_list < string, STR_SZ, STR_LN > print3 ( v3.size ( ) );
        for_each ( v3.begin ( ), v3.end ( ), print3 );
        cout << endl << endl;

        cout << "third heap - descending order:\n\n";
        get_list ( v3, D3 );
        construct_heap ( v3, greater < string > ( ) );
        for_each ( v3.begin ( ), v3.end ( ), print3 );
        cout << endl << endl;

        // print termination message
        cout << "\t\t\t*** end of program execution ***\n\n";
        return 0;
}
/***************************************************************
Function: get_list

Use: opens an input file and reads the items and inserts then in
     a vector.

Arguments: vector <T>&, const char*

Returns: void
******************************************************************/
template <class T>
void get_list(vector <T>& v, const char* path)
{
        v.clear();
        T temp; // temporary variable to hold data
        ifstream infile;
        infile.open(path);      // opens file
                if(!infile)     // tests if file opens
                {
                        cout << "Error, file coutl not be opened." << endl;
                        exit(1);
                }
        infile >> temp;
                while(!infile.eof())    // goes through to end of file
                {
                        v.push_back(temp);      // insert data into vector
                        infile >> temp; // read next entry
                }
        infile.close(); // closes the file
}
/***************************************************************
Function: construct_heap

Use: constructs a heap from the itesm of vector v and uses the
     predicate pred to comapre the items when building the heap.

Arguments: vector <T>&, P

Returns: void
***************************************************************/
template <class T, class P>
void construct_heap(vector <T>& v, P pred)
{
        make_heap(v.begin(), v.end(), pred);
        sort_heap(v.begin(), v.end(), pred);
}
/***************************************************************
Function: abs_less operator

Use: compares the items x and y and return ture if the absolute
     value of x is less than the absolute value of y;

Arguments: const T&

Returns: bool
***************************************************************/
template <class T>
bool abs_less <T>::operator()(const T&  x, const T& y) const
{
        if(abs(x) < abs(y))
        {
                return true;
        }
        else
        {
                return false;
        }
}
/***************************************************************
Constructor: print_list

Use: This is the constructors of print_list, where s is the size
     of the heap and c is used as a counter, with the default
     value of 0, that cn be used to insert the newline characters
     in printout.

Arguments: ccnst int&

Returns: void
***************************************************************/
template <class T, const int W, const int L>
print_list<T,W,L>::print_list(const int& s, const int& c)
{
        cnt = c;
        sz = s;
}
/***************************************************************
Function: print_list

Use: print out the item x of type T of a heap on stdout, where
     the template argument W is the size of the printed item,
     as an input argument to I/O function setw(), and the
     template argument L is the maximum number of items is printed
     on a single line.

Arguments: const T&

Returns: void
***************************************************************/
template <class T, const int W, const int L>
void print_list<T,W,L>::operator()(const T& x)
{
        if(cnt <= sz)
        {
                if(cnt == L)
                {
                        cout << endl;
                        cnt = 0;
                }
                cout << fixed << setprecision(2) << setw(W) << x << " ";
                cnt++;
        }
}
