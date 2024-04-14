#include <stdio.h>

void multiplication(int i, int j) {
    if(j == 10){
        printf("\n");
        multiplication(i+1, 1);
        return;
    }
    else if(i == 10) {
        return;
    }
    
    else{
        int ans = i * j;
        printf("%d*%d=%d", i, j, ans);
        
        if (j != 9)   
            printf(" ");

        multiplication(i, j+1);
    }
}

int main()
{
    multiplication(1, 1);
    return 0;
}