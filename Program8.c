#include <stdio.h>
#include <stdlib.h>

#define QUANTUM 2 // time slice for each process

typedef struct {
    int pid;    // process ID
    int burst;  // burst time
    int wait;   // wait time
    int turn;   // turnaround time
} Process;

void schedule(Process p[], int n) {
    int time = 0, done = 0;
    while (done < n) {
        for (int i = 0; i < n; i++) {
            if (p[i].burst > 0) {
                if (p[i].burst > QUANTUM) {
                    time += QUANTUM;
                    p[i].burst -= QUANTUM;
                } else {
                    time += p[i].burst;
                    p[i].wait = time - p[i].burst;
                    p[i].turn = time;
                    p[i].burst = 0;
                    done++;
                }
            }
        }
    }
}

int main() {
    Process p[] = {{1, 6, 0, 0}, {2, 8, 0, 0}, {3, 7, 0, 0}};
    int n = sizeof(p) / sizeof(p[0]);

    schedule(p, n);

    printf("Process ID\tBurst Time\tWait Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++)
        printf("%d\t\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].burst, p[i].wait, p[i].turn);

    return 0;
}
