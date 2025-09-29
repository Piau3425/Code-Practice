#include <stdio.h>
#include <math.h>

int start, end, none = 1;

int main(){

    scanf("%d %d", &start, &end);

    for(int i = start; i <= end; i++){

        int digit = 0, tmp = i, sum = 0;

        while(tmp != 0){
            tmp /= 10;
            digit++;
        }

        tmp = i;
        for(int j = 1; j <= digit; j++){
            sum += (int)pow(tmp%10, digit);
            tmp /= 10;
        }

        if(sum == i){
            printf("%d ", i);
            none = 0;
        }
    }

    if(none == 1)
        printf("none");
}