# Process ID and Parent Process ID Retrieval

## Introduction

This C program demonstrates how to retrieve and display the Process ID (PID) and Parent Process ID (PPID) using the `getpid()` and `getppid()` functions in the C standard library. Understanding process IDs is fundamental in operating systems, as they are used to identify and manage processes.

## Code Explanation

### Source Code

```c
#include<stdio.h>
#include<unistd.h>

int main()
{
    printf("Process ID: %d\n", getpid());
    printf("Parent Process ID: %d\n", getppid());
    return 0;
}
```
