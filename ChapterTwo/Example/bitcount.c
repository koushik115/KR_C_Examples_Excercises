#include <stdio.h>
int bitcount(int x);

int main(void)
{
    printf("%d", bitcount(248));

    return 0;
}

int bitcount(int x)
{
    int b;
    int count = 0;
    b = x;
    while (b != 0)
    {
        if (x & 1)
            count++;

        x >>= 1;
        b = x;
    }

    return count;
}