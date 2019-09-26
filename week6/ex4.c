#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

/*
Output:
Caught signal: 10 
(on linux)
*/

void action(int sig) { printf("Caught signal: %d\n", sig); }

int main() {
  struct sigaction handler;
  handler.sa_handler = &action;
  sigaction(SIGKILL  , &handler, NULL);//9
  sigaction(SIGSTOP, &handler, NULL);//19
  sigaction(SIGUSR1, &handler, NULL);//10

  while (1337);

  return 0;
}