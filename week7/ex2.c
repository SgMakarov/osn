#include <stdio.h>
#include <stdlib.h>
/*
output for 19: 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18
*/
int main() {
  int N;
  scanf("%d", &N);
  int *arr = (int *)malloc(sizeof(int) * N);
  for (size_t i = 0; i < N; i++) {
    arr[i] = i;
  }

  for (size_t i = 0; i < N; i++) {
    printf("%d ", arr[i]);
  }
  free(arr);
  arr = NULL;
  return 0;
}