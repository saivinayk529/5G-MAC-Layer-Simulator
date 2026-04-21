#include <stdio.h>
#include "queue.h"

#define MAX 100

Packet queue[MAX];
int front = -1, rear = -1;

void enqueue(Packet p) {
    if (rear == MAX - 1) {
        printf("Queue Full\n");
        return;
    }
    if (front == -1) front = 0;
    queue[++rear] = p;
}

Packet dequeue() {
    Packet p = {-1, ""};
    if (front == -1 || front > rear) {
        printf("Queue Empty\n");
        return p;
    }
    return queue[front++];
}

int isEmpty() {
    return (front == -1 || front > rear);
}