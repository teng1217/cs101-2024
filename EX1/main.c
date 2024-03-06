#include <stdio.h>

int main() {
    int rows = 3; 
    for (int i = 1; i <= rows; i++) {
        for (int j = 0; j < rows - i; j++) {
            printf(" ");
        }

        for (int k = 1; k <= i; k++) {
            printf("%d", i);
        }

        printf("\n");
    }

    return 0;
}

