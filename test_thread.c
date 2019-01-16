/*
to create thread, we use this function:
  int pthread_create(
                  pthread_t * thread,
                  const pthread_attr_t * attr,
                  void * (*start_routine)(void *),
                  void *arg);
*/

// void * (*start_routine)(void *) => this is callback function, eg. sorting function

#include <pthread.h>
#include <stdio.h>

void *incrementVal(void *c_parameter){
  int *c_parameter_int = (int *) c_parameter;
  while(*c_parameter_int < 20){
    (*c_parameter_int)++;
  }
  printf("Increment c is finished! \n");
  return NULL;
}

int main( ) {
  // we want to increase c and r;
  int c = 0;
  int r = 0;
  // Thread variable to reference to second thread
  pthread_t secondThread;

  // this is new thread, we do increment c
  if(pthread_create(&secondThread,
    NULL,
    incrementVal,
    &c)){
      printf("Cannot create thread!");
  }

  // this is in current thread (main), where we will do the increment r
  while(r < 20){
    r++;
  }
  printf("Increment r is finished! \n");

  // if(pthread_join(secondThread, NULL)){
  //   printf(stderr, "Error joing thread \n");
  // }

  printf("c: %d, r: %d \n", c, r);

  return 0;
}

// gcc file.c may not runnable since we have library pthread, we may need to search how to run it.
// codeblock, netbean, eclipse, tool recommended by teacher for writing C.
