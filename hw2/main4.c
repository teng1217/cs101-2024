#include <stdio.h>
#include <string.h>
int main() {
    FILE *fp;
    char filename[] = "main3.c"; 
    char line[100];
    int lineNumber = 0;

    // 嘗試以只讀方式打開本身的程式檔案
    fp = fopen(filename, "r");

    // 逐行讀取程式碼，直到文件結尾
    while (fgets(line, sizeof(line), fp)) {
            lineNumber++;
        // 檢查該行是否包含main函數
        if (strstr(line, "int main")) {
            printf("%d int main() {", lineNumber);
            break; // 找到後就不用再繼續搜尋
        }
    }


    fclose(fp);

    return 0;
}
