#include <stdio.h>

int main() {
    int rows = 6; // �]�w���r�𪺼h��

    for (int i = 1; i <= rows; i++) {
        // �b�C�@�椧�e�L�X�ťաA�ϼƦr�~�����
        for (int j = 0; j < rows - i; j++) {
            printf(" ");
        }

        // �L�X�Ʀr
        for (int k = 1; k <= i; k++) {
            printf("%d", i);
        }

        // ����
        printf("\n");
    }

    return 0;
}

