#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char** argv) {
  char ch;
  if (!strcmp(argv[1], "-a")) {
    int stdin = open("/dev/stdin", O_RDONLY);
    int stdout = open("/dev/stdout", O_WRONLY);
    int* files = malloc((argc - 1) * sizeof(int));
    for (int i = 0; i < argc - 2; i++) {
      files[i] = open(argv[i + 2], O_WRONLY | O_APPEND);
      if (files[i] == -1) {
        files[i] = open(argv[i + 2], O_WRONLY | O_CREAT, S_IRWXU);
      }
    }
    while (read(stdin, &ch, 1)) {
      for (int i = 0; i < argc - 1; i++) {
        write(files[i], &ch, 1);
      }
      write(stdout, &ch, 1);
    }
    for (int i = 0; i < argc - 1; i++) {
      close(files[i]);
    }
    free(files);
    return 0;
  }

  int stdin = open("/dev/stdin", O_RDONLY);
  int stdout = open("/dev/stdout", O_WRONLY);
  int* files = malloc((argc - 1) * sizeof(int));
  for (int i = 0; i < argc - 1; i++) {
    files[i] = open(argv[i + 1], O_WRONLY | O_TRUNC, S_IRWXU);
    if (files[i] == -1) {
      files[i] = open(argv[i + 1], O_WRONLY | O_CREAT, S_IRWXU);
    }
  }
  while (read(stdin, &ch, 1)) {
    for (int i = 0; i < argc - 1; i++) {
      write(files[i], &ch, 1);
    }
    write(stdout, &ch, 1);
  }
  for (int i = 0; i < argc - 1; i++) {
    close(files[i]);
  }
  free(files);
}