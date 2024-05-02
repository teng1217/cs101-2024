#include <stdio.h>

typedef struct {
    int* calloced_p[10]; // �ΨӰO�����t���O�������
} my_mm_t;

int g_mm[10]; // �����ܼưO����Ŷ�

my_mm_t mms; // �����ܼƺ޲z�O����

void print_calloc_array(int flag) {
    for (int i = 0; i < 10; i++) {
        (mms.calloced_p[i]) ? printf("1") : printf("0"); // �L�X�w���t���O�����m
    }
    if (!flag) {
        printf(" <- Out of space"); // �p�G�W�X�d��A��� "Out of space"
    }
    printf("\n");
}

int* my_calloc(int n, int size) {
    int av_size = 0; // �i�Τj�p
    int index;
    for (index = 0; index < 10; index++) {
        if (!mms.calloced_p[index]) {
            av_size++;                  // �p��mms�x�}���Ѿl�Ŷ����j��
        } else {
            av_size = 0;
        }

        if (av_size == size) { // ���s��Ŷ��j�󵥩�n�D���j�p
            index -= size - 1; // ��s index
            break;
        }
    }

    if (av_size < size) { // �p�G�i�ΪŶ��p��n�D�j�p�A�h�L�X "Out of space"
        print_calloc_array(0); // �NFLAG�]��0
        return NULL;
    }
    
    for (int i = 0; i < size; i++) { // �N��쪺�s��Ŷ��аO���w���t
        mms.calloced_p[index + i] = &g_mm[index];
    }
    print_calloc_array(1); // �L�X mms ����
    return &g_mm[index];
}

void my_free(int* p) {
    for (int i = 0; i < 10; i++) {
        if (mms.calloced_p[i] == p) {
            mms.calloced_p[i] = NULL; // �N���񪺰O������маO����
        }
    }
    print_calloc_array(1); // �L�X mms ����
}

int main() {
    int* np1 = my_calloc(1, 1);
    int* np2 = my_calloc(1, 2);
    int* np3 = my_calloc(1, 3);
    int* np4 = my_calloc(1, 4);
    my_free(np1);
    my_free(np4);
    int* np5 = my_calloc(1, 5);
    int* np6 = my_calloc(1, 1);
    return 0;
}