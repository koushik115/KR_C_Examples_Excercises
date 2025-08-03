#include <stdio.h>
#include <limits.h>
#include <math.h>

int main(void)
{
    int c;

    while ((c = getchar()) != EOF)
    {
        printf("1.Auto Calculation\n2.Manual Calculation\n");

        switch (c)
        {
        case '1':
            printf("----------char----------\n");
            printf("Range of signed char is from %d to %d\n", SCHAR_MIN, SCHAR_MAX);
            printf("Range of unsigned char is from %u to %u\n", 0, UCHAR_MAX);

            printf("----------short----------\n");
            printf("Range of signed short is from %d to %d\n", SHRT_MIN, SHRT_MAX);
            printf("Range of unsigned short is from %u to %u\n", 0, USHRT_MAX);

            printf("----------int----------\n");
            printf("Range of signed int is from %d to %d\n", INT_MIN, INT_MAX);
            printf("Range of unsigned int is from %u to %u\n", 0u, UINT_MAX);

            printf("----------long----------\n");
            printf("Range of signed long is from %ld to %ld\n", LONG_MIN, LONG_MAX);
            printf("Range of unsigned long is from %lu to %lu\n", 0ul, ULONG_MAX);
            break;

        case '2':
            printf("----------char----------\n");
            printf("Range of signed char is from %d to %d\n",
                   (int)(-pow(2, sizeof(char) * 8 - 1)),
                   (int)(pow(2, sizeof(char) * 8 - 1) - 1));
            printf("Range of unsigned char is from %u to %u\n", 0,
                   (unsigned int)(pow(2, sizeof(char) * 8) - 1));

            printf("----------short----------\n");
            printf("Range of signed short is from %d to %d\n",
                   (int)(-pow(2, sizeof(short) * 8 - 1)),
                   (int)(pow(2, sizeof(short) * 8 - 1) - 1));
            printf("Range of unsigned short is from %u to %u\n", 0,
                   (unsigned int)(pow(2, sizeof(short) * 8) - 1));

            printf("----------int----------\n");
            printf("Range of signed int is from %d to %d\n",
                   (int)(-pow(2, sizeof(int) * 8 - 1)),
                   (int)(pow(2, sizeof(int) * 8 - 1) - 1));
            printf("Range of unsigned int is from %u to %u\n", 0,
                   (unsigned int)(pow(2, sizeof(int) * 8) - 1));

            printf("----------long----------\n");
            printf("Range of signed long is from %ld to %ld\n",
                   (long)(-pow(2, sizeof(long) * 8 - 1)),
                   (long)(pow(2, sizeof(long) * 8 - 1) - 1));
            printf("Range of unsigned long is from %lu to %lu\n", 0ul,
                   (unsigned long)(pow(2, sizeof(long) * 8) - 1));
            break;

        default:
            if (c != '\n')
                printf("Enter Valid Command\n1.Auto Calculation\n2.Manual Calculation\n");
            break;
        }
    }

    return 0;
}
