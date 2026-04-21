#ifndef QUEUE_H
#define QUEUE_H

typedef struct {
    int id;
    char data[20];
} Packet;

void enqueue(Packet p);
Packet dequeue();
int isEmpty();

#endif