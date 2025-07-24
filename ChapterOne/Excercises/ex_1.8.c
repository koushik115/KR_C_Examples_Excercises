#include <stdio.h>

int main(void) {
    int nl, nb, nt, c;
    nl = nb = nt = 0;

    while((c = getchar()) != EOF) {
        switch (c)
        {
        case ' ':
            nb++;
            break;

        case '\t':
            nt++;
            break;

        case '\n':
            nl++;
            break;

        default:
            break;
        }
        printf("Blanks: %d\tTabs: %d\tNewLine: %d\n", nb, nt, nl);
    }
}