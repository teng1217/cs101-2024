#include <stdio.h>
#include <string.h>
int main() {
    FILE *fp;
    char filename[] = "main3.c"; 
    char line[100];
    int lineNumber = 0;

    // ���եH�uŪ�覡���}�������{���ɮ�
    fp = fopen(filename, "r");

    // �v��Ū���{���X�A�����󵲧�
    while (fgets(line, sizeof(line), fp)) {
            lineNumber++;
        // �ˬd�Ӧ�O�_�]�tmain���
        if (strstr(line, "int main")) {
            printf("%d int main() {", lineNumber);
            break; // ����N���ΦA�~��j�M
        }
    }


    fclose(fp);

    return 0;
}
