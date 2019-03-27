#include "/home/onyuksel/courses/340/progs/13s/p11/wdigraph.h"

/**************************
PROGRAM: prog11.cc
PROGRAMMER: 
DATE DUE: May 2 2013
**************************/

// This driver program can be used to test routines
// defined in class wdigraph

void proc_graph( wdigraph& );

int main()
{
        // create weighted digraph of size NO_NODES
        wdigraph g1(NO_NODES);
        // test the digraph
        proc_graph(g1);

        // create weighted digraph for size 5
        wdigraph g2(5);
        // test the digraph
        proc_graph(g2);

        // create weighted digraph for size 20
        wdigraph g3(20);
        // test the digraph
        proc_graph(g3);

        return 0;
}

/************************************************************
Function: proc_graph

Use: used to test the digraph. Prints the digraph by calling
     the member function print_graph(). Traverses the digraph
     using the depth-first search and prints the resulting paths
     by calling the member function depth_firs(); however to
     save space, it only prints the paths by skipping every
     second and third node.

Arguments: wdigraph&

Returns: void
************************************************************/
void proc_graph( wdigraph& g )
{
        // print graph
        cout << endl << "A Weighted Digraph" << endl;
        cout << "----------------" << endl;
        g.print_graph( );

        // visit nodes by depth-first search
        cout << endl << "Paths by Depth-First Search: " << endl;
        cout << "(Skip every 2nd and 3rd node to print)" << endl << endl;
                for( int i = 0; i < g.get_size ( ); i += 3 )
                {
                        g.depth_first ( i );
                }
}


#include "/home/onyuksel/courses/340/progs/13s/p11/wdigraph.h"

// default class constructor

wdigraph :: wdigraph ( int n ) : size ( n )
{
    // allocate dynamic memory

    label = vector < char > ( size );
    adj_matrix = vector < vector < int > > ( size );
    for ( int i = 0; i < size; i++ )
        adj_matrix [ i ] = vector < int > ( size );

    // assign labels to each node

    label [ 0 ] = 'A';
    for ( int i = 1; i < size; i++ )
        label [ i ] = label [ i - 1 ] + 1;

    // determine weights for links between nodes randomly
    // and build adjacency matrix

    srand ( 1 );
    for ( int i = 0; i < size; i++ ) {
        adj_matrix [ i ] [ i ] = 0;
        bool flag = false;
        for ( int j = 0; j < size; j++ ) {
            if ( j == i ) continue;
            double r = ( double ) rand ( ) / RAND_MAX;
            adj_matrix [ i ] [ j ] =
                ( r <= LINK_PROB ) ? rand ( ) % MAX_WEIGHT + 1 : 0;
            if ( adj_matrix [ i ] [ j ] > 0 ) flag = true;
        }

        // if node is not connected to any other node, then
        // connect this node to random node

        if ( size > 1 && !flag ) {
            int k; while ( ( k = rand ( ) % size ) == i ) ;
            adj_matrix [ i ] [ k ] = rand ( ) % MAX_WEIGHT + 1;
        }
    }
}
