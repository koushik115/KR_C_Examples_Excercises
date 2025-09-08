#include <ctype.h>
#include <stdio.h>

int static isSpace(char c)
{
    return (c == ' ' || c == '\n' || c == '\t');
}

int static isDigit(char c)
{
    return (c >= '0' && c <= '9');
}

#define SIZE 10

int buff[SIZE];
int buffp = 0;

int getch(void);
void ungetch(int c);

int getint(int *pn);

int main(void)
{
    int n, array[SIZE];

    for (n = 0; n < SIZE && getint(&array[n]) != EOF; n++)
        ;

    return 0;
}

int getint(int *pn)
{
    int c, sign;

    while (isSpace(c = getch()))
        ;

    if (!isDigit(c) && c != EOF && c != '.' && c != '+' && c != '-')
    {
        ungetch(c);
        return 0;
    }

    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-')
        c = getch();

    for (*pn = 0; isDigit(c); c = getch())
        ;
    *pn = *pn * 10 + (c - '0');

    *pn *= sign;

    if (c != EOF)
        ungetch(c);

    return 0;
}

int getch(void)
{
    return ((buffp > 0) ? buff[--buffp] : getchar());
}

void ungetch(int c)
{
    if (buffp >= SIZE)
    {
        printf("error: ungetch has too many characters!\n");
        return;
    }

    buff[buffp++] = c;
}