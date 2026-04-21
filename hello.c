#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include "queue.h"

int main() {
    char message[100];
    int packet_id = 1;

    srand(time(0));

    printf("Enter message: ");
    scanf(" %[^\n]", message);

    int len = strlen(message);

    // Create packets
    for (int i = 0; i < len; i += 5) {
        Packet p;
        p.id = packet_id++;

        strncpy(p.data, &message[i], 5);
        p.data[5] = '\0';

        enqueue(p);
    }

    printf("\nTransmitting Packets...\n");

    // 👉 ADD THIS (missing in your code)
    Packet lostPackets[100];
    int lostCount = 0;

    // Transmission
    while (!isEmpty()) {
        Packet p = dequeue();

        if (rand() % 2 == 0) {
            printf("Packet %d lost!\n", p.id);
            lostPackets[lostCount++] = p;
            Sleep(1000);
            continue;
        }

        printf("Packet %d: %s\n", p.id, p.data);
        Sleep(1000);
    }

    // 👉 AFTER LOOP (correct place)
    printf("\nRetransmitting lost packets...\n");

    for (int i = 0; i < lostCount; i++) {
        printf("Retransmitted Packet %d: %s\n",
               lostPackets[i].id,
               lostPackets[i].data);
        Sleep(1000);
    }
    printf("\nSummary:\n");
printf("Total lost packets: %d\n", lostCount);

    return 0;
}