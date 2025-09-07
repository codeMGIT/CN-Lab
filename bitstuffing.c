#include <stdio.h>
#include <string.h>

#define MAX 100
#define FLAG "01111110"

int main() {
    char data[MAX];
    char stuffed[2 * MAX];  // Enough space for stuffed bits
    int i, j = 0, count = 0;

    printf("Enter the message (bit string):\n");
    fgets(data, sizeof(data), stdin);
    data[strcspn(data, "\n")] = '\0'; // Remove newline

    // Start frame with FLAG
    strcpy(stuffed, FLAG);
    j = strlen(FLAG);

    for (i = 0; data[i] != '\0'; i++) {
        stuffed[j++] = data[i];

        if (data[i] == '1') {
            count++;
            if (count == 5) {       // After 5 consecutive 1s
                stuffed[j++] = '0'; // Insert 0
                count = 0;
            }
        } else {
            count = 0; // Reset counter if 0
        }
    }

    // End frame with FLAG
    strcpy(&stuffed[j], FLAG);

    printf("\nMessage after bit stuffing:\n%s\n", stuffed);

    return 0;
}
