#include <stdio.h>

#define IN  1
#define OUT 0

int main(void) {
    int c, nl, nw, nc, state;

    nl = nw = nc = 0;
    state = OUT;

    while((c = getchar()) != EOF) {
        nc++;

        if(c == '\n')
            ++nl;
        else if(c == ' ' || c == '\n' || c == '\t') 
            state = OUT;    
        else if(state == OUT) {
            state = IN;
            nw++;
        }
    }
    printf("New Character: %d\tNew Line: %d\tNew Word: %d\n", nc, nl, nw);
}