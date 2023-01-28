#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

sem_t mutex;

void* process1(void* arg)
{
    while(1)
    {
        printf("Process 1 is trying to enter critical section...\n");
        sem_wait(&mutex);
        printf("Process 1 entered critical section...\n");
        printf("Process 1 is executing...\n");
        sleep(1);
        printf("Process 1 is leaving critical section...\n");
        sem_post(&mutex);
        sleep(1);
    }
}

void* process2(void* arg)
{
    while(1)
    {
        printf("Process 2 is trying to enter critical section...\n");
        sem_wait(&mutex);
        printf("Process 2 entered critical section...\n");
        printf("Process 2 is executing...\n");
        sleep(1);
        printf("Process 2 is leaving critical section...\n");
        sem_post(&mutex);
        sleep(1);
    }
}

int main()
{
    sem_init(&mutex, 0, 1);
    pthread_t thread1, thread2;
    pthread_create(&thread1, NULL, process1, NULL);
    pthread_create(&thread2, NULL, process2, NULL);
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    sem_destroy(&mutex);
    return 0;
}
