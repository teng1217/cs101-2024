#include <stdio.h>

int main() {
    char a[] = "10001111";
    int decimalValue = strtol(a, NULL, 2); 
    printf("%X\n", decimalValue);

    return 0;
}
