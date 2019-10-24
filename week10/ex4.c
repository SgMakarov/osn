#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
  DIR* tmp = opendir("./tmp");
  if (tmp == NULL) {
    return -1;
  }
  struct dirent* de;
  char* d_names[100];
  long unsigned int d_inos[100];
  size_t count = 0;

  while ((de = readdir(tmp)) != NULL) {
    d_inos[count] = de->d_ino;
    d_names[count++] = de->d_name;
  }
  for (size_t i = 0; i < count; i++) {
    for (size_t j = i + 1; j < count; j++) {
      if(d_inos[i] == d_inos[j]){
          printf("inode number: %lu, names: %s %s\n", d_inos[i], d_names[i], d_names[j]);
      }
    }
  }

  closedir(tmp);
}