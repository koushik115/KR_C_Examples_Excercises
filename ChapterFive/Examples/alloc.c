#include <stdio.h>

#define ALLOCSIZE   10000

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

char *alloc(int n);
void afree(char *p);

int main(void) {
    char *name = alloc(8);
    name = "Koushik";
    printf("%s ", name);
    afree(name);

    return 0;
}

char *alloc(int n) {
    if(allocbuf + ALLOCSIZE - allocp >= n) {
        allocp += n;
        return allocp - n;
    }

    return NULL;
}

void afree(char *p) {
    if(p >= allocbuf && p < (allocbuf + ALLOCSIZE))
        allocp = p;
}
