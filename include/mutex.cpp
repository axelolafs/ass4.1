#include "mutex.h"
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

pthread_mutex_t sharedVariableMutex;
int gSharedVariable = 0;

void initMutex(void){
    pthread_mutex_init(&sharedVariableMutex, NULL);
}

void *incrementTask(void *param){
    while(1){
        sleep(3);

        pthread_mutex_lock(&sharedVariableMutex);

        gSharedVariable++;

        printf("Increment Task: shared is %d\n", gSharedVariable);

        pthread_mutex_unlock(&sharedVariableMutex);

    }
}

void *decrementTask(void *param){
    while(1){
        sleep(7);

        pthread_mutex_lock(&sharedVariableMutex);

        gSharedVariable--;

        printf("Decrement Task: shared var is %d\n", gSharedVariable);

        pthread_mutex_unlock(&sharedVariableMutex);
    }
}