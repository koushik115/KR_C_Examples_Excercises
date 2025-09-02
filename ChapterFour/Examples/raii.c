#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RAII_VARIABLE(vartype, varname, initval, dtor) \
    __attribute__((cleanup(dtor))) vartype varname = (initval)

static inline void freep(void *p)
{
    free(*(void **)p);
}

int main(void)
{
    // Allocate a memory from the heap to buffer
    RAII_VARIABLE(char *, buffer, malloc(100), freep);

    strcpy(buffer, "RAII in C!");

    printf("%s\n", buffer);

    return 0;
} // Deallocation of memory happens automatically!
