#include <stdio.h>

unsigned long checks;

int prime_original(unsigned long n)
{
    checks = 0;
    if (n < 2) return 0;
    for (unsigned long i = 2; i < n; i++) {
        checks++;
        if (n % i == 0) return 0;
    }
    return 1;
}

int prime_for(unsigned long n)
{
    checks = 0;
    if (n < 2) return 0;
    for (unsigned long i = 2; i <= n / i; i++) {
        checks++;
        if (n % i == 0) return 0;
    }
    return 1;
}

int prime_while(unsigned long n)
{
    checks = 0;
    if (n < 2) return 0;
    unsigned long i = 2;
    while (i <= n / i) {
        checks++;
        if (n % i == 0) return 0;
        i++;
    }
    return 1;
}

int prime_do_while(unsigned long n)
{
    checks = 0;
    if (n < 2) return 0;
    unsigned long i = 2;
    do {
        if (i > n / i) break;
        checks++;
        if (n % i == 0) return 0;
        i++;
    } while (1);
    return 1;
}

int main(void)
{
    unsigned long values[] = {97, 100, 7919, 1000003};
    int count = (int)(sizeof values / sizeof values[0]);
    for (int k = 0; k < count; k++) {
        int result = prime_for(values[k]);
        printf("%8lu %-9s improved-for divisions = %lu\n",
               values[k], result ? "prime" : "not prime", checks);
    }
    prime_original(97); printf("97 original-for divisions = %lu\n", checks);
    prime_for(97); printf("97 improved-for divisions = %lu\n", checks);
    prime_while(97); printf("97 improved-while divisions = %lu\n", checks);
    prime_do_while(97); printf("97 improved-do-while divisions = %lu\n", checks);
    return 0;
}
