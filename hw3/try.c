#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void init_file(){
    int write_array[1]={0};
    FILE* fpbin=fopen("counter.bin","r");
    if(fpbin==NULL){
        FILE* tmpfpbin=fopen("counter.bin","wb+");
        fwrite(write_array,sizeof(int),1,tmpfpbin);
        fclose(tmpfpbin);
    }else{
        fclose(fpbin);
    }
}
int get_counter(){
    int read_array[1];
    FILE* tmpfpbin=fopen("counter.bin","rb");
    fread(read_array,sizeof(int),1,tmpfpbin);
    fclose(tmpfpbin);
    return read_array[0];
}
void set_counter(int counter){
    int write_array[1];
    write_array[0]=counter;
    FILE* tmpfp=fopen("counter.bin","wb");
    fwrite(write_array,sizeof(int),1,tmpfp);
    fclose(tmpfp);
}
void redeem(){
    char getnumber[100];
    char redeemnumber1[10],redeemnumber2[10],redeemnumber3[10];
    printf("請輸入中獎號碼( 最多三個 ):");
    scanf("%s %s %s",redeemnumber1,redeemnumber2,redeemnumber3);
    if(redeemnumber1[1]=='\0'){
        redeemnumber1[1]=redeemnumber1[0];
        redeemnumber1[0]='0';
    }
    if(redeemnumber2[1]=='\0'){
        redeemnumber2[1]=redeemnumber2[0];
        redeemnumber2[0]='0';
    }
    if(redeemnumber3[1]=='\0'){
        redeemnumber3[1]=redeemnumber3[0];
        redeemnumber3[0]='0';
    }
    printf("輸入中獎號碼為: %s %s %s\n以下為中獎彩券:\n",redeemnumber1,redeemnumber2,redeemnumber3);
    FILE* redeem1=fopen("lotto[00001].txt","rb");
    FILE* redeem2=fopen("lotto[00002].txt","rb");
     while (fgets(getnumber, sizeof(getnumber), redeem1) != NULL) {
         for(int i=5;i<25;i+=3){
             if(getnumber[i]==redeemnumber1[0]&&getnumber[i+1]==redeemnumber1[1]){
                 printf("彩券 NO. 1\n號碼:%s",getnumber+4);
                 break;
             }
             else if(getnumber[i]==redeemnumber2[0]&&getnumber[i+1]==redeemnumber2[1]){
                 printf("彩券 NO. 1\n號碼:%s",getnumber+4);
                 break;
             }
             else if(getnumber[i]==redeemnumber3[0]&&getnumber[i+1]==redeemnumber3[1]){
                 printf("彩券 NO. 1\n號碼:%s",getnumber+4);
                 break;
             }
                
         }
     }
      while (fgets(getnumber, sizeof(getnumber), redeem2) != NULL) {
         for(int i=5;i<25;i+=3){
             if(getnumber[i]==redeemnumber1[0]&&getnumber[i+1]==redeemnumber1[1]){
                 printf("彩券 NO. 2\n號碼:%s",getnumber+4);
                 break;
             }
             else if(getnumber[i]==redeemnumber2[0]&&getnumber[i+1]==redeemnumber2[1]){
                 printf("彩券 NO. 2\n號碼:%s",getnumber+4);
                 break;
             }
             else if(getnumber[i]==redeemnumber3[0]&&getnumber[i+1]==redeemnumber3[1]){
                 printf("彩券 NO. 2\n號碼:%s",getnumber+4);
                 break;
             }
                
         }
     }
     
    fclose(redeem1);
    fclose(redeem2);
}
void printlotto(int counter,int num){
    char lotto_file[32];
    snprintf(lotto_file,32,"lotto[%05d].txt",counter);
    FILE *fp;
    fp = fopen(lotto_file, "w+");
    srand(1);
    int lotto[5][7];
     for(int j=0;j<num;j++){
        for(int i=0;i<7;i++){
            int random=rand()%69+1;
            int k=0;

            while(k<i){
                if(lotto[j][k]!=random){
                    k++;
                }
                else{
                    random=rand()%69+1;
                    k=0;
                }
            }
            lotto[j][i]=random;
        }
    }


    fprintf(fp,"========= lotto649 =========\n");
    fprintf(fp,"========+ No.%05d +========\n",counter);

    for(int j=0;j<num;j++){
        fprintf(fp,"[%d]:",j+1);
        for(int i=0;i<7;i++){
            if (lotto[j][i]<10 )
                fprintf(fp," 0%d",lotto[j][i]);
            else
                fprintf(fp," %d",lotto[j][i]);
        }
        fprintf(fp,"\n");
    }
      for(int j=num;j<5;j++){
             fprintf(fp,"[%d]:",j+1);
          for(int i=0;i<7;i++){
            fprintf(fp," __");
         }
        fprintf(fp,"\n");
        }
    
    
    fprintf(fp,"========= csie@CGU =========\n");
    fclose(fp);
}
int lotto(int counter){
    int num;
    printf("請問您要購買幾組樂透彩:");
    scanf("%d",&num);
    if(num==0){
        redeem();
        return counter;
    }
    else if(num>0 && num<6){
        counter++;
       printlotto(counter,num); 
       return counter;
    } 
    return counter;
}
int main()
{
    int counter;
    init_file();
    counter = get_counter();
    printf("%d\n",counter);
    counter = lotto(counter);
    set_counter(counter);
    return 0;
}