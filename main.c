#include <stdio.h>

int main() {
    int rows = 6; // 設定金字塔的層數

    for (int i = 1; i <= rows; i++) {
        // 在每一行之前印出空白，使數字居中顯示
        for (int j = 0; j < rows - i; j++) {
            printf(" ");
        }

        // 印出數字
        for (int k = 1; k <= i; k++) {
            printf("%d", i);
        }

        // 換行
        printf("\n");
    }

    return 0;
}

