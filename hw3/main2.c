#include <stdio.h>

void replace_all(char *str, char oldChar, char newChar) {
    while (*str != '\0') { // 遍歷字串，直到遇到 '\0' 字串結尾符號
        if (*str == oldChar) { // 如果當前字元等於 oldChar
            *str = newChar; // 將當前字元替換成 newChar
        }
        str++; // 移動到下一個字元
    }
}

int main() {
    char str[100], oldChar = 'a', newChar = 'A';
    scanf("%s", str);
    replace_all(str, oldChar, newChar);
    printf("%s", str);
    return 0;
}
