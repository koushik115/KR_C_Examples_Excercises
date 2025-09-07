#include <stdio.h>

// Mathematical Operations
#define ADD(x, y) ((x) + (y))
#define SUB(x, y) ((x) - (y))
#define MUL(x, y) ((x) * (y))
#define DIV(x, y) ((y) == 0 ? 0 : (x) / (y))
#define MOD(x, y) ((x) % (y))
#define SQUARE(x) ((x) * (x))
#define CUBE(x) ((x) * (x) * (x))
#define MAX(x, y) ((x) > (y) ? (x) : (y))

// Generic Macros
#define DPRINT(expr) printf(#expr " = %d\n", expr);
#define PASTE(x, y) x##y

int main(void) {
    DPRINT(ADD(1, 2));

    return 0;
}