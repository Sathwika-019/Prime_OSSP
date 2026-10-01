#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t semaphore;

void *worker(void *arg)
{
    int id = *(int *)arg;

    printf("Thread %d is waiting for the resource.\n", id);

    sem_wait(&semaphore);

    printf("Thread %d is using the resource.\n", id);
    sleep(2);

    printf("Thread %d released the resource.\n", id);

    sem_post(&semaphore);

    return NULL;
}

int main()
{
    pthread_t thread1, thread2;
    int id1 = 1;
    int id2 = 2;

    sem_init(&semaphore, 0, 1);

    pthread_create(&thread1, NULL, worker, &id1);
    pthread_create(&thread2, NULL, worker, &id2);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    sem_destroy(&semaphore);

    printf("Semaphore demonstration completed.\n");

    return 0;
}
