#include <stdio.h>

#define MAX_WORD_LEN     100

int main(void) {
    int c = 0, arrWord[MAX_WORD_LEN] = {0};
    int nchar = 0, nwhite = 0;

    while((c = getchar()) != EOF) {
        if(c == '\n' || c == ' ' || c == '\t') {
            nwhite++;
            if(nchar > 0) {
                arrWord[nchar]++;
                nchar = 0; 
            }
                
        } else {
            nchar++;
        }          
    }

    printf("Histogram:\n");

    for(int i = 0; i < MAX_WORD_LEN ; i++) {
        if(arrWord[i] > 0) {
            printf("\n%d letter word: ", i);
            for(int j = 0; j < arrWord[i]; j++)
                printf("*");
        }
    }
}
