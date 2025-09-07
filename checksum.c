#include <stdio.h>
#include <string.h>

#define MAX 100

// Function to calculate 1's complement checksum
int calculateChecksum(int data[], int n) {
    int sum = 0;

    // Sum all the data
    for (int i = 0; i < n; i++) {
        sum += data[i];

        // If overflow occurs (sum > 255 for 8-bit), wrap around
        if (sum > 255)
            sum = (sum & 0xFF) + 1;
    }

    // Take 1's complement
    int checksum = ~sum & 0xFF;

    return checksum;
}

int main() {
    int n;
    printf("Enter number of data bytes: ");
    scanf("%d", &n);

    int data[MAX];
    printf("Enter %d data bytes (0-255):\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &data[i]);

    int checksum = calculateChecksum(data, n);

    printf("Checksum (1's complement): %d\n", checksum);

    return 0;
}
