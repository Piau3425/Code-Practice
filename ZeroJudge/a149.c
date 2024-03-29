#include <stdio.h>

int loop, input, sum;

int main(){
    scanf("%d", &loop);
    for(int i = 0; i < loop; i++){
        sum = 1;
        scanf("%d", &input);
        if(input == 0){
            printf("0");
            break;
        }
        while(input != 0){
            sum *= input%10;
            input /= 10;
        }
        printf("%d\n", sum);
    }
}
