#include <stdio.h>

int main() {
    FILE *source_file, *output_file;
    char ch;
    int line_number = 1;
    // �}�ҥ�����C�y���ɮ�
    source_file = fopen("main2.c", "r");

    // �}�ҭn�g�J��txt�ɮ�
    output_file = fopen("main2.txt", "w");

    // Ū���ɮפ��e�A�üg�J��txt�ɮפ�
    fprintf(output_file, "%d: ", line_number); // ��l���
    while ((ch = fgetc(source_file)) != EOF) {
        fputc(ch, output_file);
        if (ch == '\n') { 
            fprintf(output_file, "%d ", ++line_number);
        }
    }

    // �����ɮ�
    fclose(source_file);
    fclose(output_file);

    return 0;
}
