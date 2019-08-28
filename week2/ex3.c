#include <stdio.h>
#include <string.h>

int abs(int a) {
    return a > 0 ? a : -a;
}

int min(int a, int b) {
    return a < b ? a : b;
}

void triangle(int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 2 * n - 1; ++j) {
            if (abs(j - (n - 1)) <= i)
                fputc('*', stdout);
            else fputc(' ', stdout);
        }
        fputc('\n', stdout);
    }
}

void square(int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            fputc('*', stdout);
        }
        fputc('\n', stdout);
    }
}

void right_triangle(int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i >= j)fputc('*', stdout);
            else fputc(' ', stdout);
        }
        fputc('\n', stdout);
    }
}

void angle(int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (j <= min(i, abs(n - i - 1))) fputc('*', stdout);
            else fputc(' ', stdout);
        }
        fputc('\n', stdout);
    }
}

int main(int argc, char **argv) {
    int n;
    sscanf(argv[1], "%d", &n);
    printf("choose figure to be printed (1-4): ");
    int i;
    scanf("%d", &i);
    switch (i) {
        case 1: {
            right_triangle(n);
            break;
        }
        case 2: {
            triangle(n);
            break;
        }
        case 3: {
            square(n);
            break;
        }
        case 4: {
            angle(n);
            break;
        }
        default:
            printf("wrong number\n");
    }

}