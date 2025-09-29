#include <stdio.h>

int start, goal, i = 0, sum = 0;

int main(){
    while(scanf("%d %d", &start, &goal) != EOF){
        sum = start;
        for(i = 1; sum <= goal; i++){
            sum += start+i;
        }
        printf("%d\n", i);
    }
}
