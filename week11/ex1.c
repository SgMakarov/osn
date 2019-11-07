#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>

int main() {
  
  
  int fd = open("./ex1.txt", O_RDWR);
  char *str = "This is a nice day";
  char *mem =
      mmap(NULL, strlen(str), PROT_WRITE | PROT_READ, MAP_SHARED, fd, 0);
  memcpy(mem, str, strlen(str));
  ftruncate(fd, strlen(str));
  close(fd);
  return 0;
}