#include <stdio.h>

void swap(int *i, int *j) {
    int tmp = *i;
    *i = *j;
    *j = tmp;
}

int main() {
    int i, j;
    scanf("%d %d", &i, &j);
    swap(&i, &j);
    printf("%d %d", i, j);
}