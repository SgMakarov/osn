#include <stdio.h>
#include <stdlib.h>

void* my_realloc(void* ptr, size_t size) {
  if (ptr == NULL) return malloc(size);
  if (size == 0) {
    free(ptr);
    return NULL;
  }
  free(ptr);
  ptr = malloc(size);
  return ptr;
}
int main() {
  int* ptr = malloc(10);
// ptr[1000000] = 1337; 
// printf("%d\n", *(ptr + 1000000));
// uncomment this two lines to get segfault
// otherwise output is definitely 1337
  ptr = my_realloc(ptr, sizeof(int) * 1000001);
  ptr[1000000] = 1337;
  printf("%d\n", ptr[1000000]);
}