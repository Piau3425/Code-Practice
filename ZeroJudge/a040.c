#include <stdio.h>
#include <math.h>

int start, end, none = 1; // 起始數字、結束數字、是否符合阿姆斯壯數的標記

int main(){

    scanf("%d %d", &start, &end); // 讀取輸入的起始數字和結束數字

    for(int i = start; i <= end; i++){

        int digit = 0, tmp = i, sum = 0; // 位數、暫存數字、加總值

        while(tmp != 0){ // 計算數字的位數
            tmp /= 10;
            digit++;
        }

        tmp = i;
        for(int j = 1; j <= digit; j++){ // 將每個數字的位數次方加總
            sum += (int)pow(tmp%10, digit);
            tmp /= 10;
        }

        if(sum == i){ // 如果加總值等於原數字，則輸出該數字
            printf("%d ", i);
            none = 0;
        }
    }

    if(none == 1)
        printf("none");
}
