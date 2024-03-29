#include <stdio.h>

int num, sum;
void factorial(int num);

int main(){
    while(scanf("%d", &num) != EOF){
        sum = 1;
        printf("%d! = ", num);
        if(num == 0){
            num++;
        }
        factorial(num);
        printf(" = %d\n", sum);
    }
}


void factorial(int num){
    if(num > 1){
        printf("%d * ", num);
        sum *= num;
        factorial(num-1);
    }
    else
        printf("%d", num);
}
