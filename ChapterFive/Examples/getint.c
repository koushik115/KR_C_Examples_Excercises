#include <stdio.h>
#include <ctype.h>

int static isSpace(char c)
{
    return (c == ' ' || c == '\t' || c == '\n');
}

int static isDigit(char c)
{
    return (c >= '0' && c <= '9');
}

#define SIZE 10
int buff[SIZE];
int buffp = 0;

int getch(void);
void ungetch(int);

int main(void)
{
    int n, array[SIZE], getint(int *);

    for (n = 0; n < SIZE && getint(&array[n]) != EOF; n++)
        ;

    return 0;
}

int getint(int *pn)
{
    int c, sign;

    while (isSpace(c = getchar()))
        ;

    if (!isDigit(c) && c != EOF && c != '+' && c != '-')
    {
        ungetch(c);
        return 0;
    }

    sign = (c == '-') ? -1 : 1;

    if (c == '+' || c == '-')
        c = getch();

    for (*pn = 0; isDigit(c); c = getch())
        *pn = *pn * 10 + (c - '0');

    if (c != EOF)
    {
        ungetch(c);
    }

    return c;
}

int getch(void)
{
    return ((buffp > 0) ? buff[buffp--] : getchr());
}

void ungetch(int c)
{
    if (buffp > SIZE - 1)
        printf("error: too many characters in buff!\n");
    else
        buff[buffp++] = c;
}