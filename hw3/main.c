#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
    int receipt_id;
    // int receipt_price;
    int lotto_set[5][7];
}lotto_record_t;

// 將樂透資料寫入到二進位檔案
// void writeLottoRecord(const lotto_record_t *record) {
//     FILE *fp = fopen("count.txt", "ab"); // 以附加模式打開檔案

//     // 將資料寫入到檔案中
//     fwrite(record, sizeof(lotto_record_t), 1, fp);

//     // 關閉檔案
//     fclose(fp);
// }


int main() {
    int count = 0;
    FILE *count_file = fopen("count.txt", "r");
    if (count_file != NULL) {
        fscanf(count_file, "%d", &count);
        fclose(count_file);
    }

    count++;
    count_file = fopen("count.txt", "w");
    fprintf(count_file, "%d", count);
    fclose(count_file);

    char lotto_number[6];
    sprintf(lotto_number, "%04d", count);


    printf("歡迎光臨長庚樂透彩購買機台\n");
    printf("請問您要買幾組樂透彩：");
    int num;
    int lotto_ans[3];
    scanf("%d", &num);
    if(num <= 5 && num >= 1){
        printf("以您購買的 %d 組樂透組合輸出至lotto%s.txt\n", num, lotto_number);
    }
    else if(num == 0){
        printf("請輸入中獎號碼(最多三個):\n", lotto_ans);
    }
    else{
        printf("請輸入1~5的數字\n");
        return 1; // 如果輸入不合法，直接退出程式
    }
    
    char filename[16];
    sprintf(filename, "lotto%s.txt", lotto_number);
    FILE *file_pointer;
    file_pointer = fopen(filename, "w");

    lotto_record_t lotto_record;
    lotto_record.receipt_id = lotto_number;

    fprintf(file_pointer, "=========lotto649=========\n");
    fprintf(file_pointer, "=======+ No.%s +=======\n", lotto_number);

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
                if (lotto_num[j] < 10){
                    fprintf(file_pointer, " 0%d", lotto_num[j]);

                }
                else{
                    fprintf(file_pointer, " %d", lotto_num[j]);
                }
            }
        }
        else{
            for (int j = (i - 1) * 7; j < i * 7; j++) {
                if (lotto_num[j] < 10)
                {
                    fprintf(file_pointer, " 0%d", lotto_num[j]);
                }
                else{
                    fprintf(file_pointer, " %d", lotto_num[j]);
                }
            }
        }
        fprintf(file_pointer, "\n");
    }

    for (int i = num + 1; i <= 5; i++) {
        fprintf(file_pointer, "[%d]:", i);

        for (int j = 0; j < 7; j++){
            fprintf(file_pointer, " --"); 
        }
        fprintf(file_pointer, "\n");
    }

    fprintf(file_pointer,"======== csie@CGU ========\n");
    fclose(file_pointer);

    // 寫入樂透資料到檔案中

    return 0;
}
