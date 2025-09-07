#include <stdio.h>
#include <string.h>

#define MAX 100

char data[MAX], g[20], temp[20];

void XOR(int len) {
    for(int i = 0; i < len; i++)
        temp[i] = (temp[i] == g[i] ? '0' : '1');
}

void CRC(int dataLen, int genLen) {
    int i, j;
    for(i = 0; i < genLen; i++)
        temp[i] = data[i];

    do {
        if(temp[0] == '1')
            XOR(genLen);

        // Shift left
        for(j = 0; j < genLen - 1; j++)
            temp[j] = temp[j+1];

        temp[j] = data[i++]; // bring next data bit
    } while(i <= dataLen);
}

int main() {
    int n, m, i, j;

    strcpy(g, "110000001111"); // Generator polynomial
    printf("Enter binary data: ");
    scanf("%s", data);

    n = strlen(data);
    m = strlen(g);

    printf("\nGenerator polynomial: %s\n", g);
    printf("Length of generator: %d, Length of data: %d\n", m, n);

    // Append zeros
    for(i = n; i < n + m - 1; i++)
        data[i] = '0';
    data[n + m - 1] = '\0';

    printf("Modified data with zeros: %s\n", data);

    CRC(n, m);

    printf("CRC Remainder: %s\n", temp);

    // Append remainder to original data
    for(i = n, j = 0; i < n + m - 1; i++, j++)
        data[i] = temp[j];
    data[n + m - 1] = '\0';

    printf("Final code word: %s\n", data);

    return 0;
}
