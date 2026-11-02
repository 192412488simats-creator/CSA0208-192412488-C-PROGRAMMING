#include <stdio.h>

static unsigned long calls;

int verify_disability_card(int passenger_id)
{
    calls++;
    /* Deterministic sample: every 10th passenger has a valid card. */
    return passenger_id % 10 == 0;
}

int main(void)
{
    unsigned long approved_first = 0, approved_server_first = 0;
    unsigned long calls_first, calls_server_first;

    /* Case 1: cheap senior-and-class test is evaluated before server check. */
    calls = 0;
    for (int id = 1; id <= 1000; id++) {
        int senior = (id % 4 == 0);
        int eligible_class = (id % 3 == 0);
        if ((senior && eligible_class) || verify_disability_card(id))
            approved_first++;
    }
    calls_first = calls;

    /* Case 2: server check is first, so it is called for every passenger. */
    calls = 0;
    for (int id = 1; id <= 1000; id++) {
        int senior = (id % 4 == 0);
        int eligible_class = (id % 3 == 0);
        if (verify_disability_card(id) || (senior && eligible_class))
            approved_server_first++;
    }
    calls_server_first = calls;

    printf("Cheap condition first: approved=%lu, server calls=%lu\n",
           approved_first, calls_first);
    printf("Server check first:    approved=%lu, server calls=%lu\n",
           approved_server_first, calls_server_first);

    /* Bitwise operators evaluate both operands; shown with a fresh count. */
    calls = 0;
    {
        int a = 0;
        int b = verify_disability_card(10);
        int result = a & b;
        printf("Bitwise &: result=%d, server calls=%lu\n", result, calls);
    }
    puts("If verification must always be audited, call it explicitly.");
    return 0;
}
