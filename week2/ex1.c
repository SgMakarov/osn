#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {
    int i = INT_MAX;
    float f = FLT_MAX;
    double d = DBL_MAX;
    printf("%d\n%e\n%e\n", i, f, d);
    return 0;

}