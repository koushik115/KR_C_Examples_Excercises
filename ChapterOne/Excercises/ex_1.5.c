#include <stdio.h>

int main(void) {
    int fahr, celsius;
    int lower, upper, step;
    
    lower = 0;
    upper = 300;
    step = 20;

    for(fahr = upper; fahr >= lower; fahr -= step) {
        celsius = 5 * (fahr - 32) / 9;
        printf("%d\t%d\n", fahr, celsius);
    }
    
}