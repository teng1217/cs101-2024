#include <stdio.h>
#include <string.h>

int main() {
    char a[] = "Hello";
    
    int len = strlen(a);

    for (int i = 0; i < len / 2; i++) {
        char temp = a[i];
        a[i] = a[len - i - 1];
        a[len - i - 1] = temp;
    }

    printf("反轉後的字串: %s\n", a);

    return 0;
}
