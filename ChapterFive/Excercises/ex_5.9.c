#include <stdio.h>

char *daytab[2];
char leap[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
char non_leap[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int day_of_year(int year, int month, int day);
void month_day(int year, int yearday, int *pmonth, int *pday);

int main(void)
{
    int month, day, yearday;

    daytab[0] = non_leap;
    daytab[1] = leap;

    printf("%d\n", (yearday = day_of_year(1988, 2, 1)));
    month_day(1988, yearday, &month, &day);
    printf("Month: %d\tDay = %d\n", month, day);
}

int day_of_year(int year, int month, int day)
{
    int i, leap;

    leap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;

    for (i = 1; i < month; i++)
        day += *(*(daytab + leap) + i);

    return day;
}

void month_day(int year, int yearday, int *pmonth, int *pday)
{
    int i, leap;

    leap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;

    for (i = 1; yearday > *(*(daytab + leap) + i); i++)
        yearday -= (*(*(daytab + leap) + i));

    *pmonth = i;
    *pday = yearday;
}