#include <stdio.h>

int foodLoop, eatLoop, sum, x1, x2, y1, y2;

int main(){
    while(scanf("%d %d", &foodLoop, &eatLoop) != EOF){

        int sat[foodLoop][foodLoop];

        for(int i = 0; i < foodLoop; i++){
            for(int j = 0; j < foodLoop; j++)
                scanf("%d", &sat[i][j]);
        }

        for(int i = 0; i < eatLoop; i++){
            sum = 0;
            scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

            for(int i = x1; i <= x2; i++){
                for(int j = y1; j <= y2; j++)
                    sum += sat[i-1][j-1];
            }

            printf("%d\n", sum);
        }
    }
}
