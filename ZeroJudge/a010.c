#include <stdio.h>

int main(){
    int a, x = 2, i = 0;
    scanf("%d", &a);
    while(1){
        if(a % x == 0){
            i = 0;
            while(a % x == 0){
                a /= x;
                i++;
            }
            if(i >= 2)
                printf("%d^%d", x, i);
            else
                printf("%d", x);
            if(a == 1)
                break;
            printf(" * ");
        }
        x++;
    }
}
//a是被除數 x是除數 i是除幾次
