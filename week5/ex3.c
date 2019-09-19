#include <stdio.h>
#include <pthread.h>
#define BUFFER 1337

void producer();

void consumer();

int main() {
    pthread_t tid;

    pthread_create(&tid, NULL, (void *) &producer, NULL);
    pthread_create(&tid, NULL, (void *) &consumer, NULL);

    pthread_join(tid, NULL);
}

int csleep = 0;
int psleep = 0;
int cappuccino = 0;


void producer() {
    int i = 0;
    while (1) {
        while (psleep);

        if (i % 1000000 == 0)
            printf("%d\n", cappuccino);

        if (cappuccino < BUFFER) {
            cappuccino++;
            csleep = 0;
            i++;
        } else {
            psleep = 1;
        }
    }
}

void consumer() {
    int i = 0;
    while (1) {
        while (csleep);

        if (cappuccino) {
            cappuccino--;
            psleep = 0;
            i++;
        } else {
            csleep = 1;
        }
    }
}
