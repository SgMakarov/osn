#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>

int main() {
  int fd = open("./ex1.txt", O_RDWR);
  int fd2 = open("./ex1.memcpy.txt", O_RDWR);
  struct stat *buffer = malloc(sizeof(struct stat));
  fstat(fd, buffer);
  int len = buffer->st_size;
  ftruncate(fd2, len);
  char *str = mmap(NULL, len, PROT_WRITE | PROT_READ, MAP_SHARED, fd, 0);
  char *str2 = mmap(NULL, len, PROT_WRITE | PROT_READ, MAP_SHARED, fd2, 0);
  memcpy(str2, str, len);
  close(fd2);
  close(fd);
  free(buffer);
  return 0;
}