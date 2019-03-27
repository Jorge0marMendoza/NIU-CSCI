/****************************************************************
   PROGRAM:   project4
   AUTHOR:    
   LOGON ID:  
   DUE DATE:  April 12 2015

   FUNCTION:  The program will create 4 consumer threads and 4
              producer thread. Each of the threads will loop 5
              times.  Producers will insert cookies into a buffer
              and consumers will remove them.

   INPUT:     None 

   OUTPUT:    A printed list of each thread action whether it is
              a consumer removing a cookie or a producer adding a
              cookie. Each line will have listed the current total
              number of cookies in the buffer. At the end of the
	      list will be a message informing the user that the
	      threads have been cleaned.

****************************************************************/
#include <iostream>
#include <iomanip>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <cstdlib>
#include <semaphore.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

using std::cout;
using std::endl;

//Function Prototypes
int insert_item(int);
int remove_item(int);
void *producer(void *);
void *consumer(void *);

//Global Variables
#define NUM_THREADS 4				// number of threads
#define BUFFER_SIZE 10				// size of buffer
int cookieCount;                        	// buffer counter
sem_t full;					// semaphore for the full buffer
sem_t empty;					// semaphore for the empty buffer
pthread_mutex_t mutex;				// mutex lock

int main(int argc, char *argv[])
{
	pthread_t producers[NUM_THREADS];	// initialize producer threads
	pthread_t consumers[NUM_THREADS];	// initialize consumer threads
	int rc;					// return code of the create function

	cookieCount = 0;			// initialize the cookieCount to zero
	sem_init(&empty,0,BUFFER_SIZE);		// initialize the empty semaphore to BUFFER_SIZE
	sem_init(&full,0,0);			// initialize the full semaphore to zero
	pthread_mutex_init(&mutex,NULL);	// create the mutex lock

	for(long i = 0; i < NUM_THREADS; i++)
	{
		rc = pthread_create(&producers[i], NULL, producer, (void *)i);	// create producer threads
		if(rc)				// error handling
		{
			cout << "Error: unable to create thread," << rc << endl;
			exit(-1);
		}
		rc = pthread_create(&consumers[i], NULL, consumer, (void *)i);	// create consumer threads
		if(rc)				// error handling
		{
			cout << "Error: unable to create thread," << rc << endl;
			exit(-1);
		}
	}

	for(long i = 0; i < NUM_THREADS; i++)		// loop through all threads
	{
		pthread_join(producers[i], NULL);	// wait for producer threads to finish
		pthread_join(consumers[i], NULL);	// wait for consumer threads to finish
	}

	cout << "All thread are done." << endl;

	// cleanup and exit
	pthread_mutex_destroy(&mutex);
	sem_destroy(&empty);
	sem_destroy(&full);

	cout << "Resources cleaned up." << endl;

	pthread_exit(NULL);
}

/***************************************************************
Function: insert item

Use: adds an item to the buffer, increases the cookieCount, and
     prints out a line indicating which thread is performing the
     action and the current cookie count. 

Arguments: int

Returns: int
***************************************************************/
int insert_item(int threadid)
{
	if(pthread_mutex_lock(&mutex) == -1)	// acquire the mutex lock
	{
		return -1;
	}
	cookieCount++;		// increment the counter
	cout << "Producer #" << threadid << " inserted a cookie. Total: " << cookieCount << endl;
	if(pthread_mutex_unlock(&mutex) == -1)	// release the mutex lock
	{
		return -1;
	}
	return 0;
}

/***************************************************************
Function: remove item

Use: removes an item from the buffer, decreases the cookieCount,
     and prints out a line indicatating whic thread is performing
     the action adn the current cookie count.

***************************************************************/
int remove_item(int threadid)
{
	if(pthread_mutex_lock(&mutex) == -1)	// acquire the mutex lock
	{
		return -1;
	}
	cookieCount--;		// decrement the counter
	cout << "Consumer #" << threadid << " inserted a cookie. Total: " << cookieCount << endl;
	if(pthread_mutex_unlock(&mutex) == -1)	// release the mutex lock
	{
		return -1;
	}
	return 0;
}

/***************************************************************
Function: producer

Use: alternates between calling the function to insert an item
     and sleeping for one second. Loop will run 5 times. 

Arguments: void*

Returns: void
***************************************************************/
void *producer(void *param)
{
	long threadid;
	threadid = (long) param;
	int rc;
	for(int i = 1; i <= 5; i++)	// loop through all producer threads
	{
		sem_wait(&empty);
		rc = insert_item(threadid);	// insert an item
		if(rc != 0)		// error handling
		{
			cout << "Error: unable to insert a cookie." << endl;
			pthread_exit(NULL);
		}
		sem_post(&full);
		sleep(1);		// sleep for 1 second
	}
	pthread_exit(NULL);
}
/***************************************************************
Function: consumer

Use: alternates between calling the function to remove an item
     and sleeping for one second. Loop will run 5 times.

Arguments: void*

Returns: void
***************************************************************/
void *consumer(void *param)
{
	long threadid;
	threadid = (long) param;
	int rc;
	for(int i = 1; i <= 5; i++)	// loop through all consumer threads
	{
		sem_wait(&full);
		rc = remove_item(threadid);	// remove an item
		if(rc != 0)		// error handling
		{
			cout << "Error: unable to remove cookie." << endl;
			pthread_exit(NULL);
		}
		sem_post(&empty);
	}
	pthread_exit(NULL);
}
