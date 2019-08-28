#include <stdio.h>
#include <string.h>

#define MAXLEN 1000

int main() {
    char str[MAXLEN];
    scanf("%s", str);
    for (int i = strlen(str) - 1; i >= 0; --i) {
        fputc(str[i], stdout);
    }


}