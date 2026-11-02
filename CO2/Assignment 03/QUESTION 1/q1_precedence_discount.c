#include <stdio.h>

/* Demonstrates the original expression and a readable corrected calculation. */
int main(void)
{
    double price[] = {100.0, 250.0, 400.0};
    int qty[] = {2, 3, 2};
    int senior[] = {1, 0, 1};

    puts("Bill  Original(double)  Corrected");
    for (int i = 0; i < 3; i++) {
        double gross = price[i] * qty[i];
        /* Original expression: discount and GST are both based on gross. */
        double original = gross - gross * 15 / 100 * senior[i]
                                + gross * 5 / 100;

        double discount = senior[i] ? gross * 0.15 : 0.0;
        double taxable = gross - discount;
        double tax = taxable * 0.05;
        double corrected = taxable + tax;
        if (corrected > 1000.0)
            corrected -= 50.0;

        printf("%4d  %16.2f  %9.2f\n", i + 1, original, corrected);
    }

    /* Integer division demonstration: 15 / 100 is 0 in integer arithmetic. */
    printf("Integer 15/100 = %d\n", 15 / 100);

    /* Do NOT execute count = count++ + 1: it has undefined behaviour in C. */
    puts("count = count++ + 1 is undefined behaviour; it is not executed.");
    return 0;
}
