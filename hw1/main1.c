#include <stdio.h>

int main() {
    char a[] = "AABBBCCCCddd";
    char current_char = a[0];
    int count = 1;

    for (int i = 1; a[i] != '\0'; i++) {
        if (a[i] == current_char) {
            count++;
        } else {
            printf("%c%d", current_char, count);
            current_char = a[i];
            count = 1;
        }
    }

    // 印出最後一個字元及其數量
    printf("%c%d\n", current_char, count);

    return 0;
}
