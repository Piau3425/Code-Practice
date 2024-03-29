#include <stdio.h>

int foodLoop, eatLoop, sum, start, end;

int main(){
    while(scanf("%d %d", &foodLoop, &eatLoop) != EOF){

        int sat[foodLoop];

        for(int i = 0; i < foodLoop; i++){
            scanf("%d", &sat[i]);
        }

        for(int i = 0; i < eatLoop; i++){
            sum = 0;
            scanf("%d %d", &start, &end);

            for(int i = start; i <= end; i++){
                sum += sat[i-1];
            }
            printf("%d\n", sum);
        }
    }
}
