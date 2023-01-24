#include <stdio.h>
#include <stdlib.h>

struct Process {
    int pid;
    int burstTime;
};

// Comparison function for qsort to sort processes by burst time
int comparator(const void* a, const void* b) {
    int l = ((struct Process*)a)->burstTime;
    int r = ((struct Process*)b)->burstTime;
    return (l - r);
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process processes[n];
    printf("Enter burst time for each process:\n");
    for (int i = 0; i < n; i++) {
        printf("P[%d]: ", i+1);
        scanf("%d", &processes[i].burstTime);
        processes[i].pid = i+1;
    }

    // Sort processes by burst time
    qsort(processes, n, sizeof(struct Process), comparator);

    // Print the order of execution
    printf("Order of execution:\n");
    for (int i = 0; i < n; i++) {
        printf("P[%d] ", processes[i].pid);
    }

    return 0;
}
