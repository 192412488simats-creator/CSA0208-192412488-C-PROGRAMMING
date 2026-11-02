#include <stdio.h>
/* Compile: gcc -std=c11 -Wall -Wextra q1_discount_bug.c -o q1
   Assumptions: GST 5%, senior discount 15%, extra Rs.50 off above Rs.1000.
   count = count++ + 1 is undefined behaviour, so it is shown only in a comment. */
int main(void) {
    double price[] = {100.0, 250.0, 500.0};
    int qty[] = {2, 3, 2}, senior[] = {1, 0, 1};
    int i;
    for (i = 0; i < 3; ++i) {
        double gross = price[i] * qty[i];
        /* Original expression: operators of * and / bind before + and -. */
        double buggy_total = price[i] * qty[i]
            - price[i] * qty[i] * 15 / 100 * senior[i]
            + price[i] * qty[i] * 5 / 100;
        double buggy_net = buggy_total > 1000 ? buggy_total - 50 : buggy_total;
        /* Correct calculation: discount first, then GST on discounted amount. */
        double discount = senior[i] ? gross * 0.15 : 0.0;
        double taxable = gross - discount;
        double tax = taxable * 0.05;
        double total = taxable + tax;
        double net = total > 1000 ? total - 50.0 : total;
        printf("Bill %d (senior=%d): buggy total=%.2f net=%.2f | correct total=%.2f net=%.2f\n",
               i + 1, senior[i], buggy_total, buggy_net, total, net);
    }
    printf("Integer division: 15/100=%d; floating division=%.2f\n", 15/100, 15.0/100.0);
    /* Undefined behaviour: int count=0; count = count++ + 1;
       count is modified twice without sequencing. -Wall commonly warns
       about operation on 'count' that may be undefined (-Wsequence-point). */
    return 0;
}
