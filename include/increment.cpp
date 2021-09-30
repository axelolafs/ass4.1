#include "increment.h"
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

extern pthread_mutex_t sharedVariableMutex;
extern int gSharedVariable;

void *incrementTask(void *param){
    while(1){
        sleep(3);

        pthread_mutex_lock(&sharedVariableMutex);

        gSharedVariable++;

        printf("Increment Task: shared is %d\n", gSharedVariable);

        pthread_mutex_unlock(&sharedVariableMutex);

    }
}
