#include <stdio.h>

double fahrToCel(double fahr);

int main(void) {
    int fahr;
    int lower, upper, step;
    double celsius = 0.0;
    
    lower = 0;
    upper = 300;
    step = 20;

    fahr = lower;
    printf("Fahrenheit\tCelsius\n");
    while(fahr <= upper) {
        celsius = fahrToCel(fahr);
        printf("%10d\t%7.2f\n", fahr, celsius);
        fahr += step;
    }
}

double fahrToCel(double fahr) {
    return (5.0 / 9.0 * (fahr - 32.0));
}