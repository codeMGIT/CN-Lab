#include <stdio.h>
#include <string.h>

#define MAX 100
#define FIXED_SIZE 5 // Frame length for fixed-size framing

// Function for Fixed-size Framing
void fixedFraming(char message[]) {
    int i, len = strlen(message);
    printf("\n--- Fixed Size Framing (Size = %d) ---\n", FIXED_SIZE);
    for (i = 0; i < len; i++) {
        if (i % FIXED_SIZE == 0) {
            printf("\nFrame: ");
        }
        printf("%c", message[i]);
    }
    printf("\n");
}

// Function for Variable-size Framing (Count-byte method)
void variableFramingCountByte(char message[]) {
    int i, len = strlen(message);
    int pos = 0, frameLen;
    printf("\n--- Variable Size Framing (Count Byte Method) ---\n");
    while (pos < len) {
        printf("Enter size of next frame (remaining %d chars): ", len - pos);
        scanf("%d", &frameLen);
        if (frameLen <= 0 || frameLen > (len - pos)) {
            printf("Invalid size! Try again.\n");
            continue;
        }

        // Print length and frame
        printf("Frame: [%d] ", frameLen); // count byte
        for (i = pos; i < pos + frameLen; i++) {
            printf("%c", message[i]);
        }
        printf("\n");
        pos += frameLen;
    }
}

int main() {
    char message[MAX];
    printf("Enter the message: ");
    fgets(message, MAX, stdin);
    message[strcspn(message, "\n")] = '\0'; // Remove newline from fgets

    // Fixed Framing
    fixedFraming(message);

    // Variable Framing (Count Byte - dynamic)
    variableFramingCountByte(message);

    return 0;
}
