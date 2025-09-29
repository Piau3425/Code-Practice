#include <stdio.h>

int loop, start, end, j, sum;

int main(){
    scanf("%d", &loop);
    for(int i = 1; i <= loop; i++){
        j = 1; sum = 0;
        scanf("%d %d", &start, &end);
        while(j*j < start){
            j++;
        }
        start = j;
        for(; j*j <= end; j++){

        }
        j--;
        for(; j >= start; j--){
            sum += j*j;
        }
        printf("Case %d: %d\n", i, sum);
    }
}