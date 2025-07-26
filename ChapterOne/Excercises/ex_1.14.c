#include <stdio.h>

#define ASCII_MAX_CHARACTERS 128

int main(void)
{
    int c = 0, ncharcount[ASCII_MAX_CHARACTERS + 1] = {0};

    while ((c = getchar()) != EOF)
    {
        ncharcount[c]++;
    }

    for (int i = 0; i < ASCII_MAX_CHARACTERS + 1; i++)
    {
        if (ncharcount[i] > 0)
        {
            switch (i)
            {
            case 0:
                printf("\nNUL (Null): ");
                for (int j = 0; j < ncharcount[i]; j++)
                    printf("*");
                break;
            case 1:
                printf("\nSOH (Start of Heading): ");
                for (int j = 0; j < ncharcount[i]; j++)
                    printf("*");
                break;
            case 2:
                printf("\nSTX (Start of Text): ");
                for (int j = 0; j < ncharcount[i]; j++)
                    printf("*");
                break;
            case 3:
                printf("\nETX (End of Text): ");
                for (int j = 0; j < ncharcount[i]; j++)
                    printf("*");
                break;
            case 4:
                printf("\nEOT (End of Transmission): ");
                for (int j = 0; j < ncharcount[i]; j++)
                    printf("*");
                break;
            case 5:
                printf("\nENQ (Enquiry): ");
                for (int j = 0; j < ncharcount[i]; j++)
                    printf("*");
                break;
            case 6:
                printf("\nACK (Acknowledge): ");
                for (int j = 0; j < ncharcount[i]; j++)
                    printf("*");
                break;
            case 7:
                printf("\nBEL (Bell / \\a): ");
                for (int j = 0; j < ncharcount[i]; j++)
                    printf("*");
                break;
            case 8:
                printf("\nBS (Backspace / \\b): ");
                for (int j = 0; j < ncharcount[i]; j++)
                    printf("*");
                break;
            case 9:
                printf("\nHT (Horizontal Tab / \\t): ");
                for (int j = 0; j < ncharcount[i]; j++)
                    printf("*");
                break;
            case 10:
                printf("\nLF (Line Feed / \\n): ");
                for (int j = 0; j < ncharcount[i]; j++)
                    printf("*");
                break;
            case 11:
                printf("\nVT (Vertical Tab / \\v): ");
                for (int j = 0; j < ncharcount[i]; j++)
                    printf("*");
                break;
            case 12:
                printf("\nFF (Form Feed / \\f): ");
                for (int j = 0; j < ncharcount[i]; j++)
                    printf("*");
                break;
            case 13:
                printf("\nCR (Carriage Return / \\r): ");
                for (int j = 0; j < ncharcount[i]; j++)
                    printf("*");
                break;
            case 14:
                printf("\nSO (Shift Out): ");
                for (int j = 0; j < ncharcount[i]; j++)
                    printf("*");
                break;
            case 15:
                printf("\nSI (Shift In): ");
                for (int j = 0; j < ncharcount[i]; j++)
                    printf("*");
                break;
            case 16:
                printf("\nDLE (Data Link Escape): ");
                for (int j = 0; j < ncharcount[i]; j++)
                    printf("*");
                break;
            case 17:
                printf("\nDC1 (Device Control 1): ");
                for (int j = 0; j < ncharcount[i]; j++)
                    printf("*");
                break;
            case 18:
                printf("\nDC2 (Device Control 2): ");
                for (int j = 0; j < ncharcount[i]; j++)
                    printf("*");
                break;
            case 19:
                printf("\nDC3 (Device Control 3): ");
                for (int j = 0; j < ncharcount[i]; j++)
                    printf("*");
                break;
            case 20:
                printf("\nDC4 (Device Control 4): ");
                for (int j = 0; j < ncharcount[i]; j++)
                    printf("*");
                break;
            case 21:
                printf("\nNAK (Negative Acknowledge): ");
                for (int j = 0; j < ncharcount[i]; j++)
                    printf("*");
                break;
            case 22:
                printf("\nSYN (Synchronous Idle): ");
                for (int j = 0; j < ncharcount[i]; j++)
                    printf("*");
                break;
            case 23:
                printf("\nETB (End of Transmission Block): ");
                for (int j = 0; j < ncharcount[i]; j++)
                    printf("*");
                break;
            case 24:
                printf("\nCAN (Cancel): ");
                for (int j = 0; j < ncharcount[i]; j++)
                    printf("*");
                break;
            case 25:
                printf("\nEM (End of Medium): ");
                for (int j = 0; j < ncharcount[i]; j++)
                    printf("*");
                break;
            case 26:
                printf("\nSUB (Substitute): ");
                for (int j = 0; j < ncharcount[i]; j++)
                    printf("*");
                break;
            case 27:
                printf("\nESC (Escape): ");
                for (int j = 0; j < ncharcount[i]; j++)
                    printf("*");
                break;
            case 28:
                printf("\nFS (File Separator): ");
                for (int j = 0; j < ncharcount[i]; j++)
                    printf("*");
                break;
            case 29:
                printf("\nGS (Group Separator): ");
                for (int j = 0; j < ncharcount[i]; j++)
                    printf("*");
                break;
            case 30:
                printf("\nRS (Record Separator): ");
                for (int j = 0; j < ncharcount[i]; j++)
                    printf("*");
                break;
            case 31:
                printf("\nUS (Unit Separator): ");
                for (int j = 0; j < ncharcount[i]; j++)
                    printf("*");
                break;
            case 127:
                printf("\nDEL (Delete): ");
                for (int j = 0; j < ncharcount[i]; j++)
                    printf("*");
                break;
            default:
                if (i >= 32 && i < 127)
                {
                    printf("\n%c: ", i);
                    for (int j = 0; j < ncharcount[i]; j++)
                        printf("*");
                }
                else
                {
                    printf("\nInvalid Character!!");
                }
            }
        }
    }
}