#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

#define LENGTH 64
/*
Child 1 is forked
Parent sends child 2 PID to child 1 through pipe: 28863
Parent is waiting child 2 to change state
Child 1 read child 2's PID from pipe: 28863
Child 2 is forked
Child 2 is alive
Child 2 is alive
Child 1 kills child 2
Child 1 exits
Parent ends waiting, child 2 changes state to 4991
*/
int main() {
  int p1, p2;
  int p[2];
  pipe(p);

  if (!(p1 = fork())) {
    printf("Child 1 is forked\n");
    char input[LENGTH];
    read(p[0], input, LENGTH);
    int child2;
    sscanf(input, "%d", &child2);
    printf("Child 1 read child 2's PID from pipe: %d\n", child2);
    sleep(2);
    printf("Child 1 kills child 2\n");
    kill(child2, 19);
    printf("Child 1 exits\n");
    exit(0);
  } else if (!(p2 = fork())) {
    printf("Child 2 is forked\n");
    while (1337) {
      printf("Child 2 is alive\n");
      sleep(1);
    }
  } else {
    char output[LENGTH];
    sprintf(output, "%d", p2);
    printf("Parent sends child 2 PID to child 1 through pipe: %s\n", output);
    write(p[1], output, LENGTH);

    printf("Parent is waiting child 2 to change state\n");
    int status;
    waitpid(p2, &status, WUNTRACED);
    printf("Parent ends waiting, child 2 changes state to %d\n", status);
  }

  return 0;
}