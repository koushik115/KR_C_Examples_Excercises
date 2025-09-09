#include <stdio.h>
#include <ctype.h>

#define SIZE 10
int buff[SIZE];
int buffp = 0;

static int isSpace(char c)
{
    return (c == ' ' || c == '\t');
}

static int isDigit(char c)
{
    return (c >= '0' && c <= '9');
}

int getint(int *pn);
int getch(void);
void ungetch(int c);

int main(void)
{
    int array[SIZE] = {0};

    for (int n = 0; getint(&array[n]); n++)
        ;

    return 0;
}

int getint(int *pn)
{
    int c, sign;

    while (isSpace(c = getch()))
        ;

    if (!isDigit(c) && c != '+' && c != '-')
    {
        ungetch(c);
        return 0;
    }

    sign = (c == '-') ? -1 : 1;

    if (c == '-' || c == '+')
    {
        int d = getch();
        if (!isDigit(d))
        {
            if (d != EOF)
                ungetch(d);
            return 0;
        }
        c = d;
    }

    for (*pn = 0; isDigit(c); c = getch())
        *pn = *pn * 10 + (c - '0');

    *pn *= sign;

    if (c != EOF)
        ungetch(c);

    return c;
}

int getch(void)
{
    return (buffp > 0 ? buff[--buffp] : getchar());
}

void ungetch(int c)
{
    if (buffp >= SIZE)
        printf("error: too many characters in ungetch!");
    else
        buff[buffp++] = c;
}