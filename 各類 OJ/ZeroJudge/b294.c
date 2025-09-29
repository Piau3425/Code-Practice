#include <stdio.h>

int loop, amount, sum;

int main(){
    scanf("%d", &loop);
    for(int i = 1; i <= loop; i++){
        scanf("%d", &amount);
        sum += i*amount;
    }
    printf("%d", sum);
}
