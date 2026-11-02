
#include <stdio.h>

char grade_if(int marks)
{
    if (marks < 0 || marks > 100) return '?';
    else if (marks >= 90) return 'S';
    else if (marks >= 80) return 'A';
    else if (marks >= 70) return 'B';
    else if (marks >= 60) return 'C';
    else if (marks >= 50) return 'D';
    else return 'F';
}

char grade_switch(int marks)
{
    if (marks < 0 || marks > 100) return '?';

    switch (marks / 10)
    {
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
    if (g == '?')
        printf("Invalid Marks\n");
    else if (income <= 200000 && g != 'F')
        printf("Full Scholarship\n");
    else if (income <= 400000 && g != 'F')
        printf("Partial Scholarship\n");
    else
        printf("No Scholarship\n");
}

int main()
{
    int marks[] = {100, 90, 89, 80, 79, 70,
                   69, 60, 59, 50, 49, 0, -1, 101};

    int income = 150000;

    printf("Marks  If Grade  Switch Grade\n");

    for (int i = 0; i < 14; i++)
    {
        printf("%5d     %c          %c\n",
               marks[i], grade_if(marks[i]),
               grade_switch(marks[i]));
    }

    printf("\nScholarship:\n");
    scholarship(grade_switch(95), income);

    return 0;
}
