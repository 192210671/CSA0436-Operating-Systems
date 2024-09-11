#include <stdio.h>
#include <pthread.h>

pthread_mutex_t mutex;
int shared_variable = 0;

void *process(void *arg) {
    pthread_mutex_lock(&mutex);
    shared_variable++;
    printf("Shared variable: %d\n", shared_variable);
    pthread_mutex_unlock(&mutex);
    return NULL;
}

int main() {
    pthread_t thread1, thread2;

    pthread_mutex_init(&mutex, NULL);

    pthread_create(&thread1, NULL, process, NULL);
    pthread_create(&thread2, NULL, process, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    pthread_mutex_destroy(&mutex);

    return 0;
}
