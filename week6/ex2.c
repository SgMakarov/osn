#include <stdio.h>
#include <string.h>
#include <unistd.h>
#define LENGTH 64

/*
Output:
Writing string to pipe in parent: Some text
String read from pipe by child: Some text
*/

int main() {
  int p[2];
  pipe(p);
  if (fork() == 0) {
    char input[LENGTH] = "";
    read(p[0], input, LENGTH);
    printf("String read from pipe by child: %s\n", input);
  } else {
    char output[LENGTH] = "Some text";
    printf("Writing string to pipe in parent: %s\n", output);

    write(p[1], output, LENGTH);
  }

  return 0;
}
