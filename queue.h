#ifndef QUEUE_H
#define QUEUE_H

#include<stdio.h>
#include<stdlib.h>

typedef enum {false, true} bool;

typedef struct _data {
    void *element;
    struct _data *next;
}data;

typedef struct _queue
{
    int elementSize;
    int queueSize;
    data *front;
    data *rear;
}queue;

queue* createQueue(int elementSize);
void enqueue(queue *q, void *data);
void dequeue(queue *q);
void peek(queue *q, void *value);
int queueSize(queue *q);
bool isEmpty(queue *q);
void clearQueue(queue* q);
void destroyQueue(queue *q);

#endif