#include "../include/decrement.h"
#include "../include/increment.h"
#include "../include/fifo.h"
#include <pthread.h>

pthread_t incrementTaskObj, decrementTaskObj;
pthread_mutex_t sharedVariableMutex;
// int gSharedVariable = 0;
Fifo fifo;

int main(void){
    
    pthread_mutex_init(&sharedVariableMutex, NULL);
    // initMutex();

    pthread_create(&incrementTaskObj, NULL, incrementTask, NULL);
    pthread_create(&decrementTaskObj, NULL, decrementTask, NULL);
    
    pthread_join(incrementTaskObj, NULL);
    pthread_join(decrementTaskObj, NULL);

    return 0;
}