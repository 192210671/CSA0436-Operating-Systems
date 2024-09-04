# FCFS Scheduling Algorithm

## Introduction

First-Come, First-Served (FCFS) is one of the simplest CPU scheduling algorithms. In this algorithm, the process that arrives first is executed first, without preemption. It is non-preemptive and follows a FIFO (First In, First Out) order.

## How It Works

1. **Arrival**: The process arrives in the ready queue.
2. **Execution**: The process with the earliest arrival time is selected for execution.
3. **Completion**: The selected process runs to completion before the next process begins.

## Example

### Problem Statement

Consider the following set of processes with their respective arrival times and burst times:

| Process | Arrival Time | Burst Time |
|---------|--------------|------------|
| P1      | 0            | 4          |
| P2      | 1            | 3          |
| P3      | 2            | 1          |
| P4      | 3            | 2          |

### Gantt Chart

The Gantt chart for the above processes under FCFS scheduling will be:


### Calculations

- **Waiting Time**:
  - P1: 0 - 0 = 0
  - P2: 4 - 1 = 3
  - P3: 7 - 2 = 5
  - P4: 8 - 3 = 5

- **Turnaround Time**:
  - P1: 4 - 0 = 4
  - P2: 7 - 1 = 6
  - P3: 8 - 2 = 6
  - P4: 10 - 3 = 7

### Average Waiting Time (AWT)

\[
\text{AWT} = \frac{(0 + 3 + 5 + 5)}{4} = 3.25 \text{ units}
\]

### Average Turnaround Time (ATT)

\[\text{ATT} = \frac{(4 + 6 + 6 + 7)}{4} = 5.75 \text{ units}\]

## Implementation

### Prerequisites

- Basic understanding of CPU scheduling algorithms.
- Familiarity with the C programming language.

### Explanation

- **P1** starts at time 0 and finishes at time 4.
- **P2** starts immediately after P1 at time 4 and finishes at time 7.
- **P3** starts immediately after P2 at time 7 and finishes at time 8.
- **P4** starts immediately after P3 at time 8 and finishes at time 10.

```c
#include <stdio.h>

int main() {
    int n, i;
    int arrival_time[10], burst_time[10], waiting_time[10], turnaround_time[10];
    int total_wt = 0, total_tt = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter Arrival Time and Burst Time for each process:\n");
    for(i = 0; i < n; i++) {
        printf("Process %d:\n", i + 1);
        printf("Arrival Time: ");
        scanf("%d", &arrival_time[i]);
        printf("Burst Time: ");
        scanf("%d", &burst_time[i]);
    }

    // Calculate waiting time for each process
    waiting_time[0] = 0; // First process has no waiting time
    for(i = 1; i < n; i++) {
        waiting_time[i] = waiting_time[i-1] + burst_time[i-1];
        waiting_time[i] -= arrival_time[i];
    }

    // Calculate turnaround time for each process
    for(i = 0; i < n; i++) {
        turnaround_time[i] = waiting_time[i] + burst_time[i];
        total_wt += waiting_time[i];
        total_tt += turnaround_time[i];
    }

    // Display results
    printf("\nProcess\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\n", i+1, arrival_time[i], burst_time[i], waiting_time[i], turnaround_time[i]);
    }

    printf("\nAverage Waiting Time = %.2f", (float)total_wt / n);
    printf("\nAverage Turnaround Time = %.2f\n", (float)total_tt / n);

    return 0;
}
```
