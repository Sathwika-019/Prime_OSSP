#include <stdio.h>
#include <pthread.h>

void *thread_function(void *arg)
{
    int id = *(int *)arg;

    printf("Thread %d is running.\n", id);

    return NULL;
}

int main()
{
    pthread_t thread1, thread2;
    int id1 = 1;
    int id2 = 2;

    pthread_create(&thread1, NULL, thread_function, &id1);
    pthread_create(&thread2, NULL, thread_function, &id2);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Both threads have completed.\n");

    return 0;
}
