#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 
#include <time.h>   
#define MAX 10 
void slidingWindowProtocol(int windowSize) {
    int packets[MAX], n, sent = 0, ack = 0;
    for (int i = 0; i < MAX; i++) {
        packets[i] = i + 1;
    }
    printf("Enter the number of packets to send (max %d): ", MAX);
    scanf("%d", &n);
    if (n > MAX || n <= 0) {
        printf("Invalid number of packets. Exiting...\n");
        return;
    }
    srand(time(0)); 
    printf("\nSimulating Sliding Window Protocol...\n");
    while (ack < n) {
        for (int i = 0; i < windowSize && sent < n; i++, sent++) {
            printf("Packet %d sent.\n", packets[sent]);
        }
        for (int i = 0; i < windowSize && ack < sent; i++) {
            sleep(1); 
            if (rand() % 5 == 0) { 
                printf("Acknowledgment for Packet %d lost. Retransmitting...\n", packets[ack]);
                sent = ack;
                break;
            }
            printf("Acknowledgment received for Packet %d.\n", packets[ack]);
            ack++;
        }
    }
    printf("\nAll packets sent and acknowledged successfully.\n");
}
int main() {
    int windowSize;
    printf("Enter the size of the sliding window: ");
    scanf("%d", &windowSize);
    if (windowSize <= 0) {
        printf("Invalid window size. Exiting...\n");
        return 1;
    }
    slidingWindowProtocol(windowSize);
    return 0;
}