#include "increment.h"
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include "fifo.h"

extern pthread_mutex_t sharedVariableMutex;
int counter = 0;
extern Fifo fifo;

void *incrementTask(void *param){
    while(1){
        sleep(3);

        pthread_mutex_lock(&sharedVariableMutex);

        counter++;
        if (!fifo.is_full()){
            fifo.put(counter);
        }
        else {
            // Case where values are about to be overwritten, just generate error.
            printf("Tried to overfill buffer\n");
            throw;
        }

        printf("Increment Task: counter is %d\n", counter);

        pthread_mutex_unlock(&sharedVariableMutex);

    }
}
