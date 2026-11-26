#include <stdio.h>
#include <string.h>

int main() {
    char receipt[100];
    char orderID[50];
    int start = -1, end = -1;

    printf("Input: ");
    fgets(receipt, sizeof(receipt), stdin);

    for (int i = 0; receipt[i] != '\0'; i++) {
        if (receipt[i] == '#') {
            start = i + 1;
        } else if (receipt[i] == ',' && start != -1) {
            end = i;
            break;
        }
    }

    if (start != -1 && end != -1) {
        int length = end - start;
        strncpy(orderID, &receipt[start], length);
        orderID[length] = '\0';

        printf("Output: Order ID: %s\n", orderID);
    }

    return 0;
}

