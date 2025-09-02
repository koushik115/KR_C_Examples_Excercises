#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define IS_DIGIT(x) ((x) >= '0' && (x) <= '9') ? 1 : 0

#define MAXOP 100
#define NUMBER '0'

int getop(char s[]);
void push(double f);
double pop(void);

#define MAXVAL 100

int sp = -1;
double stack[MAXVAL];

int getch(void);
void ungetch(int c);

#define BUFFERSIZE 100

char buf[BUFFERSIZE];
int bufp = 0;

int main(void)
{
    int type;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF)
    {
        switch (type)
        {
        case NUMBER:
            push(atof(s));
            break;

        case '+':
            push(pop() + pop());
            break;

        case '*':
            push(pop() * pop());
            break;

        case '-':
            op2 = pop();
            push(pop() - op2);
            break;

        case '/':
            op2 = pop();
            if (op2 != 0.0)
            {
                push(pop() / op2);
            }
            else
            {
                printf("error: zero divisor!\n");
            }

        case '\n':
            printf("\t%.8g\n", pop());
            break;

        default:
            printf("error: unknown command!\n");
            break;
        }
    }
}

void push(double f)
{
    if (sp > MAXVAL - 1)
    {
        printf("error: stack overflow!\n");
        return;
    }

    stack[++sp] = f;
}

double pop(void)
{
    if (sp < 0)
    {
        printf("error: stack underflow\n");
        exit(1);
    }

    return stack[sp--];
}

int getop(char s[])
{
    int c, i;

    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;

    s[1] = '\0';

    if (!IS_DIGIT(c) && c != '.')
        return c;

    i = 0;
    if (IS_DIGIT(c))
        while (IS_DIGIT(s[++i] = c = getch()))
            ;

    if (c == '.')
        while (IS_DIGIT(s[++i] = c = getch()))
            ;

    s[i] = '\0';

    if (c != EOF)
    {
        ungetch(c);
    }

    return NUMBER;
}

int getch(void)
{
    return (bufp > 0) ? buf[bufp--] : getchar();
}

void ungetch(int c)
{
    if (bufp >= BUFFERSIZE)
    {
        printf("ungetch: too many characters!\n");
        return;
    }
    else
    {
        buf[bufp++] = c;
    }
}