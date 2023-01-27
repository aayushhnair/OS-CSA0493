#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

sem_t mutex, db;
int readcount = 0;

void *reader(void *arg)
{
    int f;
    f = ((int)arg);
    sem_wait(&mutex);
    readcount++;
    if (readcount == 1)
        sem_wait(&db);
    sem_post(&mutex);
    printf("Reader %d is reading\n", f);
    sleep(1);
    sem_wait(&mutex);
    readcount--;
    if (readcount == 0)
        sem_post(&db);
    sem_post(&mutex);
}

void *writer(void *arg)
{
    int f;
    f = ((int) arg);
    sem_wait(&db);
    printf("Writer %d is writing\n", f);
    sleep(1);
    sem_post(&db);
}

int main()
{
    int i, b;
    pthread_t rtid[5], wtid[5];
    sem_init(&mutex, 0, 1);
    sem_init(&db, 0, 1);
    for (i = 0; i <= 2; i++)
    {
        pthread_create(&wtid[i], NULL, writer, (void *)i);
        pthread_create(&rtid[i], NULL, reader, (void *)i);
    }
    for (i = 0; i <= 2; i++)
    {
        pthread_join(wtid[i], NULL);
        pthread_join(rtid[i], NULL);
    }
    return 0;
}
