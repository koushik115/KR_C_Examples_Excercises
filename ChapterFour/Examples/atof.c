#include <ctype.h>
#include <stdio.h>

#define MAXLINE 100

double asciiToFloat(char s[]);
int getLine(char line[], int maxline);

int main(void)
{
    char line[MAXLINE] = {0};
    double sum;

    sum = 0;
    while ((getLine(line, MAXLINE)) > 0)
    {
        printf("\t%g\n", sum += asciiToFloat(line));
    }
}

int getLine(char line[], int maxline)
{
    int c, i;

    for (i = 0; (c = getchar()) != EOF && c != '\n'; i++)
        line[i] = c;

    if (c == '\n')
        line[i++] = c;

    line[i] = '\0';

    return i;
}

double asciiToFloat(char s[])
{
    double val, power;
    int i, sign;

    for (i = 0; s[i] == ' ' || s[i] == '\n' || s[i] == '\t'; i++)
        ;

    sign = (s[i] == '-') ? -1 : 1;

    if (s[i] == '+' || s[i] == '-')
        i++;

    for (val = 0.0; s[i] >= '0' && s[i] <= '9'; i++)
        val = val * 10.0 + (s[i] - '0');

    if (s[i] = '.')
        i++;

    for (power = 1.0; s[i] >= '0' && s[i] <= '9'; i++)
    {
        val = val * 10.0 + (s[i] - '0');
        power = power * 10.0;
    }

    return sign * val / power;
}