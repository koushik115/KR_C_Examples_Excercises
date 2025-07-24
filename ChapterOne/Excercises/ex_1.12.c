#include <stdio.h>

#define IN  1
#define OUT 0

int main(void) {
    int c = 0, state;

    state = OUT;
    while((c = getchar()) != EOF) {
        if(c == '\n' || c == ' ' || c == '\t') {
            state = OUT;
            putchar('\n');
    } else
        putchar(c);
  }
}