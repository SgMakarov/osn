#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/resource.h>
#include <unistd.h>
/*
ru_idrss=0 ru_ixrss=0 ru_isrss=0 ru_minflt=2629 ru_majflt=0 ru_nswap=0
ru_idrss=0 ru_ixrss=0 ru_isrss=0 ru_minflt=5195 ru_majflt=0 ru_nswap=0
ru_idrss=0 ru_ixrss=0 ru_isrss=0 ru_minflt=7756 ru_majflt=0 ru_nswap=0
ru_idrss=0 ru_ixrss=0 ru_isrss=0 ru_minflt=10317 ru_majflt=0 ru_nswap=0
ru_idrss=0 ru_ixrss=0 ru_isrss=0 ru_minflt=12878 ru_majflt=0 ru_nswap=0
ru_idrss=0 ru_ixrss=0 ru_isrss=0 ru_minflt=15439 ru_majflt=0 ru_nswap=0
ru_idrss=0 ru_ixrss=0 ru_isrss=0 ru_minflt=18000 ru_majflt=0 ru_nswap=0
ru_idrss=0 ru_ixrss=0 ru_isrss=0 ru_minflt=20561 ru_majflt=0 ru_nswap=0
ru_idrss=0 ru_ixrss=0 ru_isrss=0 ru_minflt=23122 ru_majflt=0 ru_nswap=0
ru_idrss=0 ru_ixrss=0 ru_isrss=0 ru_minflt=25683 ru_majflt=0 ru_nswap=0
*/
int main() {
  for (size_t i = 0; i < 10; i++) {
    char *l = malloc(10 * (1 << 20) * sizeof(char));
    memset(l, 0, 10 * (1 << 20) * sizeof(char));
    struct rusage ru;
    getrusage(RUSAGE_SELF, &ru);
    printf("ru_idrss=%ld ru_ixrss=%ld ru_isrss=%ld ru_minflt=%ld ru_majflt=%ld ru_nswap=%ld\n", 
    ru.ru_idrss, ru.ru_ixrss,ru.ru_isrss, ru.ru_minflt, ru.ru_majflt, ru.ru_nswap);
    sleep(1);
  }
}