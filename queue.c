#include "queue.h"
#include<string.h>

queue* createQueue(int elementSize) {
    queue *q = (queue *)malloc(sizeof(queue));
    if(q == NULL) {
        return NULL;
    }
    q->elementSize = elementSize;
    q->queueSize = 0;
    q->front = NULL;
    q->rear = NULL;
    return q;
}

void enqueue(queue *q, void *Data) {
    if(q == NULL) {
        fprintf(stderr, "Trying to insert in an empty queue");
        exit(-1);
    }
    data *insertData = (data *)malloc(sizeof(data));
    insertData->element = malloc(q->elementSize);
    insertData->next = NULL;
    memcpy(insertData->element, Data, q->elementSize);
    if(q->queueSize == 0) {
        q->front = insertData;
        q->rear = insertData;
    }
    else {
        q->rear->next = insertData;
        q->rear = insertData;
    }
    q->queueSize++;
}

void dequeue(queue *q) {
    if(isEmpty(q)) {
        fprintf(stderr, "Can't peek in empty queue!!");
        exit(-1);
    }
    data *toDelete = q->front;
	if (q->queueSize == 1)
	{
		q->front = q->rear = NULL;
	}
    else {
        q->front = q->front->next;
    }
    free(toDelete->element);
	free(toDelete);
	q->queueSize--;
}

void peek(queue *q, void *value) {
    if(isEmpty(q)) {
        fprintf(stderr, "Can't peek in empty queue!!");
        exit(-1);
    }
    memcpy(value, q->front->element, q->elementSize);
}

int queueSize(queue *q) {
    return q->queueSize;
}

bool isEmpty(queue *q) {
    if(q == NULL || q->queueSize == 0) return true;
    else return false;
}

void clearQueue(queue* q) {

}

void destroyQueue(queue *q) {

}