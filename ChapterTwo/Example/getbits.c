#include <stdio.h>

unsigned int getbits(int x, int p, int n);

int main(void)
{
    printf("%d\n", getbits(255, 4, 3));

    return 0;
}

unsigned int getbits(int x, int p, int n)
{
    return ((x >> (p - n + 1)) & ~(~0 << n));
}