#include <stdio.h>

int main() {
    int rows = 6; // 砞﹚娥糷计

    for (int i = 1; i <= rows; i++) {
        // –︽ぇ玡フㄏ计﹡い陪ボ
        for (int j = 0; j < rows - i; j++) {
            printf(" ");
        }

        // 计
        for (int k = 1; k <= i; k++) {
            printf("%d", i);
        }

        // 传︽
        printf("\n");
    }

    return 0;
}

