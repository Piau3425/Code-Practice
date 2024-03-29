#include <stdio.h>

char idEng[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int id, check, sum = 0, temp, num[] = {10, 11, 12, 13, 14, 15, 16, 17, 34, 18, 19, 20, 21, 22, 35, 23, 24, 25, 26, 27, 28, 29, 32, 30, 31, 33};

int main(){
    scanf("%d", &id);

    check = id%10;
    id /= 10;

    // 計算身分證號碼前九位數字的加權和
    for(int i = 1; i <= 8; i++){
        sum += id%10*i;
        id /= 10;
    }

    // 用一個整數陣列儲存每個英文字母所對應的數字
    // 例如 A->10、B->11、C->12，以此類推
    // 用這個陣列和身分證號碼計算出的加權和、最後一位數字
    // 來判斷身分證號碼是否正確
    for(int i = 0; i < 26; i++){
        temp = num[i]%10*9 + num[i]/10;

        if(check == 10-(sum+temp)%10)
            printf("%c", idEng[i]);
        else if((sum+temp)%10 == 0 && check == (sum+temp)%10)
            printf("%c", idEng[i]);
    }
}
