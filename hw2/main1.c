#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main() {
    printf("�w����{�����ֳz�m�ʶR���x\n");
    printf("�аݱz�n�R�X�ռֳz�m�G");
    int num;
    scanf("%d", &num);
    if(num <= 5 && num >= 1){
        printf("�H�z�ʶR�� %d �ռֳz�զX��X��lotto.txt\n", num);
    }
    else{
        printf("�п�J1~5���Ʀr\n");
        return 1; // �p�G��J���X�k�A�����h�X�{��
    }
    
    time_t curtime;
    time(&curtime);
    char *timed=ctime(&curtime);
    timed[strlen(timed)-1]=0;

    FILE *file_pointer;
    file_pointer = fopen("lotto.txt", "w");

    fprintf(file_pointer, "=========lotto649=========\n");
    fprintf(file_pointer,"= %s =\n",timed);

    srand(time(NULL));

    int lotto_num[36];
    int num_generated = 0;

    while (num_generated < 36) {
        int random_number = rand() % 69 + 1;

        int is_duplicate = 0;
        for (int i = 0; i < num_generated; i++) {
            if (lotto_num[i] == random_number) {
                is_duplicate = 1;
                break;
            }
        }

        if (!is_duplicate) {
            lotto_num[num_generated] = random_number;
            num_generated++;
        }
    }

    for (int i = 1; i <= num; i++) {
        fprintf(file_pointer, "[%d]:", i);

        if (i == 5){ 
            for (int j = (i - 1) * 7; j < 35; j++) {
                fprintf(file_pointer, "%d ", lotto_num[j]);
            }
        }
        else{
            for (int j = (i - 1) * 7; j < i * 7; j++) {
                fprintf(file_pointer, "%d ", lotto_num[j]);
            }
        }

        fprintf(file_pointer, "\n");
    }

    for (int i = num + 1; i <= 5; i++) {
        fprintf(file_pointer, "[%d]:", i);

        for (int j = 0; j < 7; j++){
            fprintf(file_pointer, "-- "); 
        }

        fprintf(file_pointer, "\n");
    }

    fprintf(file_pointer,"========= csie@CGU =========\n");

    fclose(file_pointer);

    return 0;
}