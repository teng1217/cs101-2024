#include <stdio.h>

int main() {
    FILE *source_file, *output_file;
    char ch;
    int line_number = 1;
    // 開啟本身的C語言檔案
    source_file = fopen("main2.c", "r");

    // 開啟要寫入的txt檔案
    output_file = fopen("main2.txt", "w");

    // 讀取檔案內容，並寫入到txt檔案中
    fprintf(output_file, "%d: ", line_number); // 初始行數
    while ((ch = fgetc(source_file)) != EOF) {
        fputc(ch, output_file);
        if (ch == '\n') { 
            fprintf(output_file, "%d ", ++line_number);
        }
    }

    // 關閉檔案
    fclose(source_file);
    fclose(output_file);

    return 0;
}
