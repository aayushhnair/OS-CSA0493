#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_SIZE 1024  /* Size of shared memory segment */

int main() {
    key_t key;
    int shmid;
    char *data;

    /* Generate a unique key for the shared memory segment */
    key = ftok("shmfile", 65);

    /* Create the shared memory segment */
    shmid = shmget(key, SHM_SIZE, 0666|IPC_CREAT);

    /* Attach the shared memory segment to the process's address space */
    data = (char*) shmat(shmid, NULL, 0);

    /* Process 1: Write data to shared memory */
    strcpy(data, "Hello, Process 2!");
    printf("Process 1: Written to shared memory: %s\n", data);

    /* Detach the shared memory segment from the process's address space */
    shmdt(data);

    /* Process 2: Read data from shared memory */
    data = (char*) shmat(shmid, NULL, 0);
    printf("Process 2: Read from shared memory: %s\n", data);

    /* Detach and remove the shared memory segment */
    shmdt(data);
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}
