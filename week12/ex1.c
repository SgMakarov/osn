#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char** argv) {
  for (size_t i = 0; i < 1000000000; i++) {
    printf("a");
  }

  int random = open("/dev/random", O_RDONLY);
  int output = open("ex1.txt", O_WRONLY);

  char rndstr[20];
  read(random, rndstr, 20);
  write(output, rndstr, 20);
  close(random);
  close(output);
}