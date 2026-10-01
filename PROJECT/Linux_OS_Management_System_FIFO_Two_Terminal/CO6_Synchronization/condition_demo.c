#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

int data_ready = 0;

pthread_mutex_t lock;
pthread_cond_t condition;

void *producer(void *arg)
{
    sleep(2);

    pthread_mutex_lock(&lock);

    data_ready = 1;
    printf("Producer: Data is ready.\n");

    pthread_cond_signal(&condition);

    pthread_mutex_unlock(&lock);

    return NULL;
}

void *consumer(void *arg)
{
    pthread_mutex_lock(&lock);

    while (data_ready == 0)
    {
        printf("Consumer: Waiting for data...\n");
        pthread_cond_wait(&condition, &lock);
    }

    printf("Consumer: Data received.\n");

    pthread_mutex_unlock(&lock);

    return NULL;
}

int main()
{
    pthread_t producer_thread, consumer_thread;

    pthread_mutex_init(&lock, NULL);
    pthread_cond_init(&condition, NULL);

    pthread_create(&consumer_thread, NULL, consumer, NULL);
    pthread_create(&producer_thread, NULL, producer, NULL);

    pthread_join(consumer_thread, NULL);
    pthread_join(producer_thread, NULL);

    pthread_cond_destroy(&condition);
    pthread_mutex_destroy(&lock);

    printf("Condition variable demonstration completed.\n");

    return 0;
}
