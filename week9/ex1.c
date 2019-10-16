#include <stdio.h>
#include <stdlib.h>
#define COUNTER_SIZE 32u
/*
for counter of 8 bits
10 frames:
        hit/miss: 0.009082 hits: 9 misses: 991
50 frames:
        hit/miss: 0.053741 hits: 51 misses: 949
100 frames:
        hit/miss: 0.102536 hits: 93 misses: 907

for counter of 32 bits:

10 frames:
        hit/miss: 0.010101 hits: 10 misses: 990
50 frames:
        hit/miss: 0.058201 hits: 55 misses: 945
100 frames:
        hit/miss: 0.113586 hits: 102 misses: 898
*/

int main(int argc, char** argv) {
  FILE* references_file = fopen("ex1.txt", "r");
  int N;
  sscanf(argv[1], "%d", &N);
  int* loaded = (int*)malloc(N * sizeof(int));
  unsigned long long pages[1000];
  for (size_t i = 0; i < N; i++) {
    loaded[i] = -1;  // there are no page with index -1, so no pages are loaded
                     // in the beginning
  }

  for (size_t i = 0; i < 1000; i++) {
    pages[i] = 0;
  }

  int hits = 0;
  int misses = 0;
  while (!feof(references_file)) {
    unsigned int reference, hit = 0;
    fscanf(references_file, "%d", &reference);
    int oldest = 0;
    for (size_t i = 0; i < 1000; i++) {
      pages[i] >>= 1;
    }

    for (size_t i = 0; i < N; ++i) {
      if (loaded[i] == -1) {  // we did not met referenced page and there are
                              // still free cells
        oldest = i;
        break;
      }
      if (loaded[i] == reference) {
        hit = 1;
        break;
      }
      oldest = pages[loaded[oldest]] > pages[loaded[i]] ? i : oldest;
    }
    pages[reference] |= (1 << (COUNTER_SIZE - 1));

    if (hit) {
      hits++;
      continue;
    }
    loaded[oldest] = reference;
    misses++;
  }
  printf("%d frames:\n\thit/miss: %lf hits: %d misses: %d\n", N,
         ((double)hits / misses), hits, misses);
  fclose(references_file);
}