#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//copied and pasted ex3, as it already works properly with background processes and args
int main() {
    char input[1024];
    while (strcmp("exit\n", input)) {
        fputs("> ", stdout);
        fgets(input, 1024, stdin);
        system(input);
    }

}