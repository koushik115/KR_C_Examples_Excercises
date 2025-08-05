#include <stdio.h>

int hexcharacters(char hex);
int hextoint(char hex[]);

int main(void)
{
    char hexNumbers[] = "DEAD";
    printf("%d", hextoint(hexNumbers));

    return 0;
}

int hexcharacters(char hex)
{
    char hexNum[] = "0123456789ABCDEF";

    for (int i = 0; hexNum[i] != '\0'; i++)
    {
        if (hexNum[i] == hex)
            return i;
    }

    return -1;
}

int hextoint(char hex[])
{
    int dec = 0;

    for (int i = 0; hex[i] != '\0'; i++)
    {
        int hexchar = hexcharacters(hex[i]);
        if (hexchar == -1)
            return -1;
        dec = dec * 16 + hexchar;
    }

    return dec;
}