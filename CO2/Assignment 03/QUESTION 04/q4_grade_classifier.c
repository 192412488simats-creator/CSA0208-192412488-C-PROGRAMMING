#include <stdio.h>

char grade_if(int marks)
{
    if (marks < 0 || marks > 100) return '?';
    if (marks >= 90) return 'S';
    if (marks >= 80) return 'A';
    if (marks >= 70) return 'B';
    if (marks >= 60) return 'C';
    if (marks >= 50) return 'D';
    return 'F';
}

char grade_switch(int marks)
{
    if (marks < 0 || marks > 100) return '?';
    switch (marks / 10) {
        case 10:
        case 9: return 'S';
        case 8: return 'A';
        case 7: return 'B';
        case 6: return 'C';
        case 5: return 'D';
        default: return 'F';
    }
}

void scholarship(char g, int income)
{
    if (g == '?') puts("Invalid marks");
    else if (g != 'F' && income <= 200000) puts("Full scholarship");
    else if (g != 'F' && income <= 400000) puts("Partial scholarship");
    else puts("No scholarship");
}

int main(void)
{
    int marks[] = {100, 90, 89, 80, 79, 70, 69, 60, 59, 50, 49, 0, -1, 101};
    int n = (int)(sizeof marks / sizeof marks[0]);
    puts("Marks  Else-if  Switch");
    for (int i = 0; i < n; i++)
        printf("%5d  %7c  %6c\n", marks[i], grade_if(marks[i]), grade_switch(marks[i]));
    printf("Scholarship for 95 marks and Rs.150000 income: ");
    scholarship(grade_switch(95), 150000);
    puts("Fall-through note: omitting a break in a non-returning switch case executes the next case too.");
    return 0;
}
