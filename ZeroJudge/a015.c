#include <stdio.h>

int row, col, data[100][100];

int main(){
    while(scanf("%d %d", &row, &col) != EOF){
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                scanf("%d", &data[i][j]);
            }
        }

        for(int i = 0; i < col; i++){
            for(int j = 0; j < row; j++){
                printf("%d ", data[j][i]);
            }
            printf("\n");
        }
    }
}
