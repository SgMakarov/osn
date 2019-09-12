#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {
    char input[1024];
    while (strcmp("exit\n", input)) {
        fputs("> ", stdout);
        fgets(input, 1024, stdin);
        system(input);
    }

}