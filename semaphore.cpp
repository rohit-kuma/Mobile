#include<iostream>
#include <pthread.h>    //Pthread function prototypes
#include <stdio.h>
#include <semaphore.h>  // Semaphore function prototypes

 

static int val = 0;

 

/*Function to increment global variable*/

void *threadinc(void *arg)

{

  printf("%s\n",__FUNCTION__);

  while(1)

  {

   /*Wait for read thread to print*/

    sem_wait((sem_t *) arg);

    val++;

  }

}

 

/*Fuction to read and print val*/

void *threadread(void *arg)

{

  printf("%s\n",__FUNCTION__);

  while(1)

  {

    printf("%d\n",val);

    /*Inform the increment thread to increment val*/

    sem_post((sem_t *) arg);

    //sleep(1);  // Sleep to increment it sequentially

  }

}

 

/* Create 2 thread one to increment a global variable 

   and another one to read and print it. 

    Also, syncronisze them using semaphore  */

main()

{

  pthread_t tidI, tidR;

  void *ret;

  sem_t sem;

 

/*Create semaphore to synchronize the threads*/

  sem_init(&sem, 0, 0);

 

  // Create increment thread

  pthread_create(&tidI, NULL, &threadinc, &sem);

  //Create read and print thread.

  pthread_create(&tidR, NULL, &threadread, &sem);

  // Wait on threads

  pthread_join(tidI, &ret);

  pthread_join(tidR, &ret);

  sem_destroy(&sem);

}

