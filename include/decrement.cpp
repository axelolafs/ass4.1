#include "decrement.h"
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include "fifo.h"

extern pthread_mutex_t sharedVariableMutex;
// extern int gSharedVariable;
extern Fifo fifo;

void *decrementTask(void *param){
    while(1){
        sleep(7);

        pthread_mutex_lock(&sharedVariableMutex);

        // gSharedVariable--;

        // printf("Decrement Task: shared is %d\n", gSharedVariable);
        printf("Value from FIFO: %d\n", fifo.get());

        pthread_mutex_unlock(&sharedVariableMutex);

    }
}
