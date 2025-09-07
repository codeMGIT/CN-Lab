#include <stdio.h>
#include <string.h>

#define FLAG '$'
#define ESC '@'

int main() {
    char data[25], stuff[50], dstuff[50];
    int length, i, j;

    // Input the message
    printf("Enter the message: ");
    scanf("%s", data);  // Note: stops at space, use fgets() for spaces

    length = strlen(data);

    // ---------------- Byte Stuffing ----------------
    stuff[0] = FLAG; // start flag
    for (i = 0, j = 1; data[i] != '\0'; i++) {
        if (data[i] != FLAG && data[i] != ESC) {
            stuff[j++] = data[i]; // normal character
        } else { 
            stuff[j++] = ESC;     // add escape
            stuff[j++] = data[i]; // add original character
        }
    }
    stuff[j++] = FLAG; // end flag
    stuff[j] = '\0';

    printf("Stuffed message is: %s\n", stuff);

    // ---------------- Byte Destuffing ----------------
    printf("Destuffing the message...\n");
    length = strlen(stuff);
    printf("Length of stuffed message: %d\n", length);

    for (i = 1, j = 0; stuff[i] != '\0'; i++) { // skip starting FLAG
        if (stuff[i] != FLAG && stuff[i] != ESC) {
            dstuff[j++] = stuff[i]; // normal character
        } else if (stuff[i] == ESC) {
            i++; // skip escape
            dstuff[j++] = stuff[i]; // copy the actual FLAG or ESC
        }
    }
    dstuff[j] = '\0';

    printf("DeStuffed message is: %s\n", dstuff);

    return 0;
}
