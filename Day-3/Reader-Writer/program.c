#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

sem_t writeLock;
pthread_mutex_t readLock;
int readCount = 0, data = 0;

void *reader(void *arg) {
    pthread_mutex_lock(&readLock);
    readCount++;
    if (readCount == 1)
        sem_wait(&writeLock);
    pthread_mutex_unlock(&readLock);

    printf("Reader read data: %d\n", data);

    pthread_mutex_lock(&readLock);
    readCount--;
    if (readCount == 0)
        sem_post(&writeLock);
    pthread_mutex_unlock(&readLock);

    return NULL;
}

void *writer(void *arg) {
    sem_wait(&writeLock);
    data++;
    printf("Writer wrote data: %d\n", data);
    sem_post(&writeLock);

    return NULL;
}

int main() {
    pthread_t r1, r2, w1;

    sem_init(&writeLock, 0, 1);
    pthread_mutex_init(&readLock, NULL);

    pthread_create(&r1, NULL, reader, NULL);
    pthread_create(&w1, NULL, writer, NULL);
    pthread_create(&r2, NULL, reader, NULL);

    pthread_join(r1, NULL);
    pthread_join(w1, NULL);
    pthread_join(r2, NULL);

    sem_destroy(&writeLock);
    pthread_mutex_destroy(&readLock);

    return 0;
}
