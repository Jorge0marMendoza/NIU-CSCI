/***************************
PROGRAM: Assignment 5
PROGRAMMER: 
DATE DUE: Feburary 28 2013
***************************/

#include "/home/onyuksel/courses/340/progs/13s/p5/prog5.h"

int simClock = 0;
bool f1 = true;

int main()
{
        srand(SEED);
        MS ms;  // initialize the mulitset for cust objects
        MS::iterator itr;
        stat s; // initialize stat object
        event e;        // initialize event object
        int id = 1;

        init_vars(e, s);        // initialize the struct objects
                while(simClock < SIM_TIME)
                {
                        if(simClock == e.next_arr)      // cust arrives
                        {
                                Arrival(e, id, ms);     // track customer
                                id++;   // increase cust id num
                        }
                        if(simClock == e.next_dept)     // cust leaves
                        {
                                Departure(e, ms, s);    // track customer
                        }
                        if(ms.empty())  // tests if multiset is empty
                        {
                                f1 = false;
                        }
                        else
                        {
                                f1 = true;
                        }

                        simClock = update_clock(e, f1); // updates simClock
                }
        print_fin_stat(s);

        return 0;
}

/***************************************************************
Function: init_vars

Use: initializes the values in structures e and s to proper values

Arguments: event& e, stat& s

Returns: void
***************************************************************/
void init_vars(event& e, stat& s)
{
        e.next_arr = 0;
        e.next_dept = SIM_TIME + 1;
        s.num_dept = 0;
        s.tot_shop = 0;
}
/***************************************************************
Function: Arrival

Use: creates an object for the arriving customer with id number,
     initializes the arrival and departure times for that object,
     and then inserts the object into the multiset. Updates the
     timing values of structure e.

Arguments: event& e, const int& id, MS& ms

Returns: void
***************************************************************/
void Arrival(event& e, const int& id, MS& ms)
{
        cust c;
        c.id = id;      // customer id
        c.atime = arr_time(simClock);   // customer arrival

        ms.insert(c);   // insert customer into multiset

        e.next_arr = arr_time(simClock);        // next arrival time

        MS::iterator itr;
        itr = ms.begin();

        e.next_dept = dept_time(simClock);      // next depature time
}
/***************************************************************
Function: Departure

Use: removes the object fro the departing customer from the
     multiset and updates the value next_dept of struture e. It
     updates the statistical values in the structure s by calling
     the function update_fin_stat().

Arguments: event& e, MS& ms, stat& s

Returns: void
***************************************************************/
void Departure(event& e, MS& ms, stat& s)
{
        cust c1;
        MS::iterator itr;
        itr = ms.begin();
        ms.erase(itr);  // remove previous customer

                if(!ms.empty()) // test if mutliset is empty
                {
                        ms.begin();     // next customer in line
                        e.next_dept = dept_time(simClock);      // next depature time
                }
        update_fin_stat(s, c1);
}
/***************************************************************
Function: arr_time

Use: generates a random number of the inter-arrival time for a
     customer and it returns the arrival time of the next customer
     by calling the function rnd() to get a random number in the
     range [MIN_INT_ARR, MAX_INT_ARR], where clock is the current
     time for the simulation clock

Arguments: const int&

Returns: int
***************************************************************/
int arr_time(const int& clock)
{
        int i = rnd(MIN_INT_ARR, MAX_INT_ARR) + clock;  // generates random numbers
        return i;
}
/***************************************************************
Function: dept_time

Use: generates a random number for the grocery picking up time of
     the new customer enters into the store, in the range [MIN_PICK,
     MAX_PICK] and then it generates a second random number for
     the time spent in the checkout line for that customer, in the
     range [MIN_SERV, MAX_SERV]. Summing up these two random
     numbers yields the total ime that the customer spend in the
     store, where clock is the current time of the simulation
     clock.

Arguments: const int&

Returns: int
***************************************************************/
int dept_time(const int& clock)
{
        int i = rnd(MIN_PICK, MAX_PICK);
        int j = rnd(MIN_SERV, MAX_SERV);        //generates random numbers

        return i + j + clock;   // adds the time in store and time in checkout
}
/****************************************************************
Function: update_clock

Use: updates the simulation clock to the time of the earliest
     one of two possible events specified in the structure e
     using the condition given by the Boolean variable flag,
     where flag is true if the multiset is not empty; otherwise
     it is false.

Arguments: const event& e, const bool& flag

Returns: int
***************************************************************/
int update_clock(const event& e, const bool& flag)
{
        int crnt_Time;
        crnt_Time = e.next_arr;
                if(flag == true)
                {
                        if(e.next_dept < crnt_Time)
                        {
                                crnt_Time = e.next_dept;
                        }
                }
        return crnt_Time;
}
/***************************************************************
Function: update_fin_stat

Use: computes the shopping time: total time form arrival to
     departure for that customer, updates the values in structure
     s, and it also increments the number of departures from the
     store, and if the number of departures bedomes a multiple of
     SAMPLE_INT, then it prints out the customer number, id,
     arrival, depature, and shopping times.

Arguments: stat& s, const cust& c

Returns: void
***************************************************************/
void update_fin_stat(stat& s, const cust& c)
{
        s.num_dept++;   // increase departed customers
        s.tot_shop += c.dtime - c.atime;        // sum of total shopping time
                if(s.num_dept % SAMPLE_INT == 0)
                {
                        cout << "Customer Number: " << s.num_dept << " " << "Customer ID: " << c.id << " " << "Arrival Time: " << c.atime << "Departure Time: " << c.dtime << "Shopping Time: " << c.dtime - c.atime << " " <<  endl;
                }
}
/***************************************************************
Function: print_fin_stat

Use: prints out the total number of customers departed from the
     store and the total simulation time SIM_TIME, which is the
     time that the simulation stops. It also computes the average
     values over all customers departed from the store at the time
     SIM_TIME and prints out these values on standard output.

Arguments: stat& s

Returns: void
***************************************************************/
void print_fin_stat(stat& s)
{
        cout << "Total customers: " << s.num_dept << endl;
        cout << "Total Simulation Time: " << SIM_TIME;  // time at which simClock stops
        // compute average values over all customers departed from store
}
/***************************************************************
Function: cmp::operator

Use: compares the depature times for customers c1 and c2

Arguments: stat& s, const cust& c

Returns: bool
***************************************************************/
bool cmp::operator()(const cust& c1, const cust& c2) const
{
        if(c1.dtime == c2.dtime)        // test if they are equal
        {
        return true;    // they are equal
        }
        else
        {
        return false;   // they are not equal
        }
}
/***************************************************************
Function: rnd

Use: generates a random number in the range [low, high] for the
     given seed value

Arguments: const int&

Returns: int
***************************************************************/
int rnd(const int& low, const int& high)
{
        int i;
        srand(SEED);    // initialize the RNG
        i = rand()%(high - low + 1) + low;      // execute within the range
        return i;
}
