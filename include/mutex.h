#ifndef MUTEX_H
#define MUTEX_H

void initMutex(void);
void *incrementTask(void *param);
void *decrementTask(void *param);

#endif