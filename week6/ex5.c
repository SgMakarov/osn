#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

/*
The program prints 10 times "I'm alive" and terminates
*/

int main() {
  int n;
  if (n = fork()) {
    sleep(10);
    kill(n, 15);
  } else
    while (1337) {
      printf("I'm alive\n");
      sleep(1);
    }

  return 0;
}