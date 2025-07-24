#include <stdio.h>

int main(void) {
    int c;

    c = getchar() != EOF;
    putchar(c);
}