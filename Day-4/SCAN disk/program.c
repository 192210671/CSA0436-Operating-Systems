#include <stdio.h>
#include <stdlib.h>

void scan(int requests[], int n, int head, int disk_size, int direction) {
    int total_movement = 0, i;

    // Sort the requests
    for (i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (requests[j] > requests[j+1]) {
                int temp = requests[j];
                requests[j] = requests[j+1];
                requests[j+1] = temp;
            }
        }
    }

    // SCAN towards left or right
    if (direction == 0) { // Left
        for (i = n-1; i >= 0 && requests[i] >= head; i--);
        for (; i >= 0; i--) {
            printf("Move to %d\n", requests[i]);
            total_movement += abs(head - requests[i]);
            head = requests[i];
        }
        total_movement += head;  // Move to 0
        head = 0;
        printf("Move to 0\n");
    } else { // Right
        for (i = 0; i < n && requests[i] <= head; i++);
        for (; i < n; i++) {
            printf("Move to %d\n", requests[i]);
            total_movement += abs(head - requests[i]);
            head = requests[i];
        }
        total_movement += disk_size - 1 - head;  // Move to disk end
        head = disk_size - 1;
        printf("Move to %d\n", head);
    }

    printf("Total head movement = %d\n", total_movement);
}

int main() {
    int n, head, disk_size, direction;

    printf("Enter disk size: ");
    scanf("%d", &disk_size);
    printf("Enter number of requests: ");
    scanf("%d", &n);

    int requests[n];
    printf("Enter requests: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &requests[i]);
    }

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("Enter direction (0 for left, 1 for right): ");
    scanf("%d", &direction);

    scan(requests, n, head, disk_size, direction);

    return 0;
}
