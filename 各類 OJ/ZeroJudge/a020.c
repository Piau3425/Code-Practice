#include <stdio.h>

char city, id[10];
int total, weight[] = {8, 7, 6, 5, 4, 3, 2, 1};

int main(){
    scanf("%c%s", &city, &id); // 讀入城市英文字母和身份證號碼

    if(city >= 65 && city <=72) // 將城市英文字母轉換成對應的數字
        city -= 55;
    else if(city >= 74 && city <= 78)
        city -= 56;
    else if(city >= 80 && city <= 86)
        city -= 57;
    else if(city == 'X' || city == 'Y')
        city -= 58;
    else if(city == 'I')
        city = 34;
    else if(city == 'O')
        city = 35;
    else if(city == 'W')
        city = 32;
    else if(city == 'Z')
        city = 33;

    total = city%10*9 + city/10 + (id[8]-48); // 計算身份證號碼總和
    for(int i = 0; i < 8; i++){
        total += (id[i]-48)*weight[i];
    }

    if(total % 10 == 0) // 判斷身份證號碼是否為真
        printf("real");
    else
        printf("fake");
}
