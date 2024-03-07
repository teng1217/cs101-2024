#include <stdio.h>

int main() {
    // 三個陣列
    int a[] = {0, 1, 2};
    char b[] = {'A', 'B', 'C'};
    float c[] = {1.1, 1.2, 1.3};

    FILE *fp = fopen("a.bin", "wb");

        // 寫入三個陣列
        fwrite(a, sizeof(int), sizeof(a) / sizeof(int), fp);
        fwrite(b, sizeof(char), sizeof(b) / sizeof(char), fp);
        fwrite(c, sizeof(float), sizeof(c) / sizeof(float), fp);

        fclose(fp);
    

    fp = fopen("a.bin", "rb");

    if (fp != NULL) {
        fread(a, sizeof(int), sizeof(a) / sizeof(int), fp);
        fread(b, sizeof(char), sizeof(b) / sizeof(char), fp);
        fread(c, sizeof(float), sizeof(c) / sizeof(float), fp);

        fclose(fp);
    } else {
        printf("無法開啟檔案\n");
        return 1; // 程式結束並回傳錯誤碼
    }

    for (int i = 0; i < sizeof(a) / sizeof(int); i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    for (int i = 0; i < sizeof(b) / sizeof(char); i++) {
        printf("%c ", b[i]);
    }
    printf("\n");

    for (int i = 0; i < sizeof(c) / sizeof(float); i++) {
        printf("%.1f ", c[i]);
    }
    printf("\n");

    return 0; // 程式正常結束
}
