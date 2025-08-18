#include <stdio.h>
#include <string.h>

#define MAXLINE 100
void itoa(int num, char s[], int width);
void reverse(char s[]);

int main(void)
{
    int num = -831;
    char str[MAXLINE] = {0};
    itoa(num, str, 10);

    printf("%s", str);
    return 0;
}

void itoa(int num, char s[], int width)
{
    int i, sign;

    if ((sign = num) < 0)
        num = -num;

    i = 0;
    do
    {
        s[i++] = (num % 10) + '0';
    } while ((num /= 10) > 0);

    if (sign < 0)
        s[i++] = '-';

    while (width != 0)
    {
        s[i++] = ' ';
        width--;
    }

    s[i] = '\0';

    reverse(s);
}

void reverse(char s[])
{
    int i, j;

    for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
    {
        char c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}