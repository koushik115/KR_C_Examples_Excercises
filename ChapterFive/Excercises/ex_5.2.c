#include <stdio.h>
#include <ctype.h>

#define SIZE 10

float buff[SIZE];
int buffp = 0;

int getch(void);
void ungetch(int c);

int getfloat(float *pn);

int static isSpace(char c)
{
    return (c == ' ' || c == '\n' || c == '\t');
}

int static isDigit(char c)
{
    return (c >= '0' && c <= '9');
}

int main(void)
{
    float array[SIZE] = {0.0};

    for (int n = 0; n < SIZE && getfloat(&array[n]) != EOF; n++)
        ;

    return 0;
}

int getfloat(float *pn)
{
    int c, sign;
    float pow = 1.0;

    while (isSpace(c = getch()))
        ;

    if (!isDigit(c) && c != '+' && c != '-' && c != '.')
    {
        ungetch(c);
        return 0;
    }

    sign = c == '-' ? -1 : 1;

    if (c == '-' || c == '+')
    {
        int d = getch();
        if (!isDigit(d) && d != '.')
        {
            if (d != EOF)
                ungetch(d);
            return 0;
        }
        c = d;
    }

    for (*pn = 0.0; isDigit(c); c = getch())
        *pn = *pn * 10.0 + (c - '0');

    if (c == '.')
    {
        c = getch();
        for (; isDigit(c); c = getch())
        {
            *pn = *pn * 10.0 + (c - '0');
            pow *= 10.0;
        }
    }

    if (c != EOF)
        ungetch(c);

    *pn = (*pn / pow) * sign;

    return c;
}