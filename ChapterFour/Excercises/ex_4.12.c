#include <stdio.h>
#include <string.h>

#define MAXVAL 100

void integerToAscii(long long int integer, char Asciistr[]);

int main(void)
{
    char Asciistr[MAXVAL] = {0};
    integerToAscii(123456789, Asciistr);
    printf("%s", Asciistr);
}

void integerToAscii(long long int integer, char Asciistr[])
{
    static int i = 0, negInteger = 0;

    if (integer < 0)
    {
        integer = -integer;
        negInteger = 1;
    }

    if (integer / 10)
    {
        integerToAscii(integer / 10, Asciistr);
    }

    if (negInteger)
    {
        Asciistr[i++] = '-';
        negInteger = 0;
    }

    Asciistr[i++] = (integer % 10) + '0';
    Asciistr[i] = '\0';
}