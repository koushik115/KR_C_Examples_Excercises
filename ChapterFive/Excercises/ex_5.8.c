#include <stdio.h>

char daytab[2][13] =
    {{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
     {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};

int day_of_year(int year, int month, int day);
int month_day(int year, int yearday, int *pmonth, int *pday);

int main(void)
{
    int month, day;

    printf("Day of year: %d\n", day_of_year(1988, 2, 1));
    if (month_day(1988, 60, &month, &day))
        printf("Month: %d\tDay: %d\n", month, day);
    else
        printf("error: invalid moth or day!\n");

    return 0;
}

int day_of_year(int year, int month, int day)
{
    int i, leap;

    if (!(day >= 1 && day <= 31) || !(month >= 1 && month <= 12))
        return 0;

    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;

    for (i = 1; i < month; i++)
        day += daytab[leap][i];

    return day;
}

int month_day(int year, int yearday, int *pmonth, int *pday)
{
    int i, leap;

    if (yearday < 0 || yearday > 365)
        return 0;

    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;

    for (i = 1; yearday > daytab[leap][i]; i++)
        yearday -= daytab[leap][i];

    *pmonth = i;
    *pday = yearday;
}