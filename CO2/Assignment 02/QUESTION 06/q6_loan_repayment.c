
#include <stdio.h>

int main()
{
    double balance, rate, repayment;
    double interest, payment, total_interest = 0;
    int month = 0;

    printf("Enter loan amount: ");
    scanf("%lf", &balance);

    printf("Enter monthly interest rate (%%): ");
    scanf("%lf", &rate);

    printf("Enter monthly repayment: ");
    scanf("%lf", &repayment);

    if (balance <= 0 || rate < 0 || repayment <= 0)
    {
        printf("Invalid input\n");
        return 0;
    }

    rate = rate / 100.0;

    if (repayment <= balance * rate)
    {
        printf("Repayment is too small. Loan will not decrease.\n");
        return 0;
    }

    printf("\nMonth  Interest  Payment  Balance\n");

    while (balance > 0.005)
    {
        if (month == 360)
        {
            printf("Maximum 360 months reached.\n");
            break;
        }

        month++;

        interest = balance * rate;
        interest = (long)(interest * 100 + 0.5) / 100.0;

        balance += interest;
        total_interest += interest;

        payment = repayment;

        if (payment > balance)
            payment = balance;

        balance -= payment;
        balance = (long)(balance * 100 + 0.5) / 100.0;

        printf("%5d  %8.2f  %7.2f  %8.2f\n",
               month, interest, payment, balance);
    }

    if (balance <= 0.005)
    {
        printf("\nLoan fully repaid!\n");
        printf("Total months: %d\n", month);
        printf("Total interest: Rs.%.2f\n", total_interest);
    }

    return 0;
}
