#include <stdio.h>

void decodeString(char *input) {
    while (*input) {
        char letter = *input++;
        int count = *input - '0';

        for (int i = 0; i < count; ++i) {
            printf("%c", letter);
        }
        ++input;
    }
}

int main() {
    char a[] = "A4B1C3f3";
    decodeString(a);

    return 0;
}
