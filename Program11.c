#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>

#define N 5 /* Number of philosophers */

sem_t chopsticks[N]; /* semaphores representing chopsticks */

void *philosopher(void *num) {
    int i = *((int *)num);
    printf("Philosopher %d is thinking\n", i+1);
    while (1) {
        /* philosopher is hungry */
        printf("Philosopher %d is hungry\n", i+1);

        /* wait for left chopstick */
        sem_wait(&chopsticks[i]);
        printf("Philosopher %d picked up left chopstick %d\n", i+1, i+1);

        /* wait for right chopstick */
        sem_wait(&chopsticks[(i+1)%N]);
        printf("Philosopher %d picked up right chopstick %d\n", i+1, (i+1)%N+1);

        /* eat */
        printf("Philosopher %d is eating\n", i+1);
        sleep(3);

        /* release chopsticks */
        sem_post(&chopsticks[i]);
        printf("Philosopher %d released left chopstick %d\n", i+1, i+1);
        sem_post(&chopsticks[(i+1)%N]);
        printf("Philosopher %d released right chopstick %d\n", i+1, (i+1)%N+1);

        /* think */
        printf("Philosopher %d is thinking\n", i+1);
        sleep(3);
    }
}

int main() {
    int i;
    pthread_t thread_id[N];
    int philosophers[N];
    for (i = 0; i < N; i++) {
        sem_init(&chopsticks[i], 0, 1);
    }

    for (i = 0; i < N; i++) {
        philosophers[i] = i;
        pthread_create(&thread_id[i], NULL, philosopher, &philosophers[i]);
    }

    for (i = 0; i < N; i++) {
        pthread_join(thread_id[i], NULL);
    }

    for (i = 0; i < N; i++) {
        sem_destroy(&chopsticks[i]);
    }
    return 0;
}
