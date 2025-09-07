#include <stdio.h>
#include <string.h>

char a[50];
char b[50];
char flag[8] = "01111110";

int main() {
    int i = 0, j = 8, n, k;

    printf("Enter the message:\n");
    gets(a); // Unsafe, but kept as in original code

    strcpy(b, flag); // Start frame with FLAG
    n = strlen(a);

    for (k = 0; k < n; k++) {
        if (a[k] == '0' && a[k + 1] == '1' && a[k + 2] == '1' &&
            a[k + 3] == '1' && a[k + 4] == '1' && a[k + 5] == '1') {

            b[j] = '0';
            b[j + 1] = '1';
            b[j + 2] = '1';
            b[j + 3] = '1';
            b[j + 4] = '1';
            b[j + 5] = '1';
            b[j + 6] = '0';
            i = i + 6;
            j = j + 7;
        }
        b[j++] = a[i++];
    }

    strcat(b, flag); // End frame with FLAG

    printf("\nMessage after bit Stuffing\n");
    puts(b);

    return 0;
}
