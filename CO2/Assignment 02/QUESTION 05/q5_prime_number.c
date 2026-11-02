
#include <stdio.h>

unsigned long checks = 0;

int prime_for(unsigned long n)
{
    checks = 0;
    if (n < 2) return 0;

    for (unsigned long i = 2; i * i <= n; i++)
    {
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
    while (i * i <= n)
    {
        checks++;
        if (n % i == 0) return 0;
        i++;
    }
    return 1;
}

int prime_do(unsigned long n)
{
    checks = 0;
    if (n < 2) return 0;

    unsigned long i = 2;

    do
    {
        if (i > n / i) break;

        checks++;
        if (n % i == 0) return 0;
        i++;

    } while (1);

    return 1;
}

/* Original method: checks every divisor up to n-1 */
int prime_original(unsigned long n)
{
    checks = 0;
    if (n < 2) return 0;

    for (unsigned long i = 2; i < n; i++)
    {
        checks++;
        if (n % i == 0) return 0;
    }
    return 1;
}

int main()
{
    unsigned long tickets[] = {97, 100, 7919, 1000003};

    for (int k = 0; k < 4; k++)
    {
        int p = prime_for(tickets[k]);

        printf("%8lu %-9s divisions = %lu\n",
               tickets[k],
               p ? "prime" : "not prime",
               checks);
    }

    printf("\nComparison of loop versions:\n");

    prime_original(97);
    printf("Original for: %lu divisions\n", checks);

    prime_for(97);
    printf("Improved for: %lu divisions\n", checks);

    prime_while(97);
    printf("Improved while: %lu divisions\n", checks);

    prime_do(97);
    printf("Improved do-while: %lu divisions\n", checks);

    return 0;
}
