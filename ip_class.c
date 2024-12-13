#include <stdio.h>

int main() {
    int b1,b2,b3,b4;

    printf("Enter the first octet of the IPv4 address: ");
    scanf("%d%d%d%d", &b1,&b2,&b3,&b4);

    if (b1 >= 1 && b1 <= 127)
        printf("Class A\n");
    else if (b1 >= 128 && b1 <= 191)
        printf("Class B\n");
    else if (b1 >= 192 && b1 <= 223)
        printf("Class C\n");
    else if (b1 >= 224 && b1 <= 239)
        printf("Class D \n");
    else if (b1 >= 240 && b1 <= 255)
        printf("Class E \n");
    else
        printf("Invalid IPv4 address\n");

    return 0;
}
