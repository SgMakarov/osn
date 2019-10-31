#include <stdio.h>
#include <unistd.h>

/*
printf already uses line buffer
*/
int main() {
  printf("H");
  sleep(1);
  printf("e");
  sleep(1);
  printf("l");
  sleep(1);
  printf("l");
  sleep(1);
  printf("o");
  sleep(1);
}