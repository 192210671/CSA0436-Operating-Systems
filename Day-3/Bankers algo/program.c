
#include <stdio.h>

int main() {
    int n, m, i, j, k;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the number of resources: ");
    scanf("%d", &m);

    int allocation[n][m], max[n][m], available[m], need[n][m];
    int finished[n], safeSequence[n], count = 0;

    printf("Enter the allocation matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            scanf("%d", &allocation[i][j]);

    printf("Enter the maximum matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            scanf("%d", &max[i][j]);

    printf("Enter the available resources: ");
    for (i = 0; i < m; i++)
        scanf("%d", &available[i]);

    // Calculate the need matrix
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            need[i][j] = max[i][j] - allocation[i][j];

    for (i = 0; i < n; i++)
        finished[i] = 0;

    // Banker's algorithm
    while (count < n) {
        int found = 0;
        for (i = 0; i < n; i++) {
            if (finished[i] == 0) {
                int flag = 1;
                for (j = 0; j < m; j++) {
                    if (need[i][j] > available[j]) {
                        flag = 0;
                        break;
                    }
                }

                if (flag == 1) {
                    for (k = 0; k < m; k++)
                        available[k] += allocation[i][k];

                    safeSequence[count++] = i;
                    finished[i] = 1;
                    found = 1;
                }
            }
        }

        if (found == 0) {
            printf("The system is not in a safe state.\n");
            return -1;
        }
    }

    printf("The system is in a safe state.\nSafe sequence: ");
    for (i = 0; i < n; i++)
        printf("%d ", safeSequence[i]);
    printf("\n");

    return 0;
}
