#include <stdio.h>

unsigned long checks;

/* Baseline: test every divisor from 2 through sqrt(n). */
int prime_baseline(unsigned long n)
{
    checks = 0;
    if (n < 2) return 0;
    for (unsigned long i = 2; i <= n / i; i++) {
        checks++;
        if (n % i == 0) return 0;
    }
    return 1;
}

/* Redesign: handle 2 separately, then test odd divisors only. */
int prime_optimized(unsigned long n)
{
    checks = 0;
    if (n < 2) return 0;
    if (n == 2) return 1;
    checks++;
    if (n % 2 == 0) return 0;

    for (unsigned long i = 3; i <= n / i; i += 2) {
        checks++;
        if (n % i == 0) return 0;
    }
    return 1;
}

int main(void)
{
    unsigned long values[] = {97, 100, 7919, 1000003};
    int count = (int)(sizeof values / sizeof values[0]);
    puts("Number    Result      Baseline checks  Redesigned checks");
    for (int k = 0; k < count; k++) {
        int p1 = prime_baseline(values[k]);
        unsigned long old_checks = checks;
        int p2 = prime_optimized(values[k]);
        unsigned long new_checks = checks;
        printf("%-9lu %-11s %-16lu %lu\n", values[k],
               (p1 && p2) ? "prime" : "not prime", old_checks, new_checks);
    }
    return 0;
}
