#include <stdio.h>

int main(void) {
    int c = 0;

    while((c = getchar()) != EOF) {
        switch (c)
        {
        case '\t':
            putchar('\\');
            putchar('t');
            break;

        case '\b':
            putchar('\\');
            putchar('b');
            break;   
            
        case '\\':
            putchar('\\');
            putchar('\\');
            break;                

        default:
            putchar(c);
            break;
        }
    }
}