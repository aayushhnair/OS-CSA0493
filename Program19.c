#include <pthread.h>
#include<stdio.h>

pthread_mutex_t mutex;

void *process1() {
    pthread_mutex_lock(&mutex);
    // critical section
    pthread_mutex_unlock(&mutex);
}

void *process2() {
    pthread_mutex_lock(&mutex);
    // critical section
    pthread_mutex_unlock(&mutex);
}

int main() {
    pthread_t thread1, thread2;
    pthread_mutex_init(&mutex, NULL);
    pthread_create(&thread1, NULL, process1, NULL);
    pthread_create(&thread2, NULL, process2, NULL);
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_mutex_destroy(&mutex);
    return 0;
}
