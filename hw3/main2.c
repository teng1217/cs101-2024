#include <stdio.h>

void replace_all(char *str, char oldChar, char newChar) {
    while (*str != '\0') { // �M���r��A����J�� '\0' �r�굲���Ÿ�
        if (*str == oldChar) { // �p�G��e�r������ oldChar
            *str = newChar; // �N��e�r�������� newChar
        }
        str++; // ���ʨ�U�@�Ӧr��
    }
}

int main() {
    char str[100], oldChar = 'a', newChar = 'A';
    scanf("%s", str);
    replace_all(str, oldChar, newChar);
    printf("%s", str);
    return 0;
}
