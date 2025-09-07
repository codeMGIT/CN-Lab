#include <stdio.h>
#include <math.h>

int main() {
    int a, b, c, d, prefix;

    printf("Enter an IPv4 address (x.x.x.x/prefix): ");
    scanf("%d.%d.%d.%d/%d", &a, &b, &c, &d, &prefix);

    unsigned int ip = (a << 24) | (b << 16) | (c << 8) | d;
    unsigned int mask = prefix == 0 ? 0 : 0xFFFFFFFF << (32 - prefix);
    unsigned int network = ip & mask;
    unsigned int broadcast = network | ~mask;

    int host_bits = 32 - prefix;
    unsigned int usable_hosts = (host_bits == 0) ? 0 : pow(2, host_bits) - 2;

    unsigned int first_host = (usable_hosts > 0) ? network + 1 : 0;
    unsigned int last_host = (usable_hosts > 0) ? broadcast - 1 : 0;

    printf("\nSubnet Mask: %d.%d.%d.%d\n",
           (mask >> 24) & 0xFF,
           (mask >> 16) & 0xFF,
           (mask >> 8) & 0xFF,
           mask & 0xFF);

    if (usable_hosts > 0) {
        printf("First Host: %d.%d.%d.%d\n",
               (first_host >> 24) & 0xFF,
               (first_host >> 16) & 0xFF,
               (first_host >> 8) & 0xFF,
               first_host & 0xFF);

        printf("Last Host: %d.%d.%d.%d\n",
               (last_host >> 24) & 0xFF,
               (last_host >> 16) & 0xFF,
               (last_host >> 8) & 0xFF,
               last_host & 0xFF);
    }

    printf("Usable Hosts: %u\n", usable_hosts);

    return 0;
}
