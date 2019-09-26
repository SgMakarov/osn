#include <stdio.h>
#include <string.h>
#include <unistd.h>

/*
Output:
String to be written to pipe: Some text
Reading from pipe
String read from pipe: Some text
*/
char first[64] = "Some text", second[64];

int main() {
  int p[2];

  pipe(p);

  printf("String to be written to pipe: %s\n", first);
  write(p[1], first, strlen(first));

  printf("Reading from pipe\n");
  read(p[0], second, strlen(first));
  printf("String read from pipe: %s\n", second);

  return 0;
}
