#include <stdio.h>

int main(void) {
    int c = 0, blankcharacter = 0;

    while((c = getchar()) != EOF) {
        if(c != ' ') {
            putchar(c);
            blankcharacter = 0;
        } else if(c == ' ' && !blankcharacter) {
            putchar(c);
            blankcharacter = 1;
        }
    }

    return 0;
}