#include <stdio.h>

int main(void)
{
    double balance, rate, repayment, total_interest = 0.0;
    int month = 0;

    printf("Enter loan amount: ");
    if (scanf("%lf", &balance) != 1) return 1;
    printf("Enter monthly interest rate (%%): ");
    if (scanf("%lf", &rate) != 1) return 1;
    printf("Enter monthly repayment: ");
    if (scanf("%lf", &repayment) != 1) return 1;

    if (balance <= 0.0 || rate < 0.0 || repayment <= 0.0) {
        puts("Invalid input.");
        return 1;
    }
    rate /= 100.0;
    if (repayment <= balance * rate) {
        puts("Repayment is not greater than the first month's interest; loan will not decrease.");
        return 0;
    }

    puts("Month  Interest  Payment  Balance");
    while (balance > 0.005) {
        double interest, payment;
        if (month >= 360) {
            puts("Safety limit reached: loan is not fully repaid.");
            break;
        }
        month++;
        interest = balance * rate;
        interest = (long)(interest * 100.0 + 0.5) / 100.0;
        total_interest += interest;
        balance += interest;
        payment = repayment < balance ? repayment : balance;
        balance -= payment;
        balance = (long)(balance * 100.0 + 0.5) / 100.0;
        printf("%5d  %8.2f  %7.2f  %8.2f\n", month, interest, payment, balance);
    }
    if (balance <= 0.005) {
        puts("Loan fully repaid.");
        printf("Total months: %d\nTotal interest: Rs.%.2f\n", month, total_interest);
    }
    return 0;
}
