#ifndef __OS_H__
#define __OS_H__

#define _XOPEN_SOURCE 600
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <fcntl.h>
#include <signal.h>
#include <unistd.h>

// Definitions for a Task
typedef struct _Task* PTASK;
int Task_create(PTASK *new_task, char *name, void (*func)(void *param), void *param, unsigned long long period, unsigned long long estimated_duration);

// Definitions for the Ready queue
typedef struct _ReadyQueue* PREADYQUEUE;
int Readyqueue_create(PREADYQUEUE *queue);
int Readyqueue_enqueue(PREADYQUEUE queue, PTASK task);

// Definitions for the scheduler
typedef struct _Scheduler* PSCHEDULER;

#define SCHEDULING_SHORTEST_JOB_FIRST       1
#define SCHEDULING_EARLIEST_DEADLINE_FIRST  2

int Scheduler_create(PSCHEDULER *scheduler, int policy, PREADYQUEUE ready_queue, unsigned long long interval);

#endif