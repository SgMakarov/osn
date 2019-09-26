#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

/*
Output:
On ctrl+c: Caught signal: 2
*/
void interrupt_action(int sig) { printf("Caught signal: %d\n", sig); }

int main() {
  struct sigaction handler;
  handler.sa_handler = &interrupt_action;
  sigaction(2, &handler, NULL);
  while (1337);

  return 0;
}