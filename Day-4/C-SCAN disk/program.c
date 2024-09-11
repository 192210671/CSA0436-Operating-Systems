#include <stdio.h>
#include <stdlib.h>

void cscan(int req[], int n, int head, int disk_size) {
    int total_movement = 0, i, j;
    
    // Sort the request array
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (req[j] > req[j + 1]) {
                int temp = req[j];
                req[j] = req[j + 1];
                req[j + 1] = temp;
            }
        }
    }

    // Move towards right first
    for (i = 0; i < n; i++) {
        if (req[i] >= head) {
            total_movement += abs(req[i] - head);
            printf("Move to track %d\n", req[i]);
            head = req[i];
        }
    }

    // Move to the end of the disk and back to the start
    total_movement += abs(disk_size - 1 - head);
    printf("Move to track %d\n", disk_size - 1);

    total_movement += disk_size - 1;
    printf("Move to track 0\n");

    head = 0;

    // Now service remaining requests
    for (i = 0; i < n; i++) {
        if (req[i] < head) {
            total_movement += abs(req[i] - head);
            printf("Move to track %d\n", req[i]);
            head = req[i];
        }
    }

    printf("\nTotal head movement: %d\n", total_movement);
}

int main() {
    int n, head, disk_size;
    
    printf("Enter the disk size: ");
    scanf("%d", &disk_size);

    printf("Enter the number of requests: ");
    scanf("%d", &n);

    int req[n];
    printf("Enter the request sequence: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &req[i]);
    }

    printf("Enter the initial head position: ");
    scanf("%d", &head);

    cscan(req, n, head, disk_size);

    return 0;
}
