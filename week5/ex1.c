#include <stdio.h>
#include <pthread.h>


void print(int x) {
    printf("Output from thread № %d\n\n", x);
    pthread_exit(NULL);
}

int main() {
    pthread_t tid;

    for (int i = 0; i < 10; i++) {
        pthread_create(&tid, NULL,(void *) &print, i);
        printf("Thread № %d is created\n", i);
        pthread_join(tid, NULL);
    }
}