#include <ctype.h>
#include <stdio.h>

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