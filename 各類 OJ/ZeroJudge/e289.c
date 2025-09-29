#include <stdio.h>

int purple, length, beautiful = 0, color[250000], gate = 0;

int main(){
    scanf("%d %d", &purple, &length);
    int check[purple];
    for(int i = 0; i < length; i++)
        scanf("%d", &color[i]);
    for(int i = 0; i + purple <= length; i++){
        for(int j = 0; j < purple; j++)
            check[j] = color[i+j];
        //printf("list = %d %d %d\n", check[0], check[1], check[2]);
        gate = 0;
        for(int j = 0; j < purple; j++){
            for(int k = 1; j + k <= purple-1; k++){
                //printf("j = %d k = %d\n", check[j], check[j+k]);
                if(check[j] == check[j+k]){
                    gate = 1;
                    //printf("gate = %d\n", gate);
                    break;
                }
                //printf("gate = %d\n", gate);
            }

            //printf("%d ", check[j]);
        }
        if(gate == 0){
            beautiful++;
            //printf("i = %d, gate = %d, beautiful = %d\n", i, gate, beautiful);
        }
        printf("\n");
        /*gate = 0;
        for(int j = 0; j < purple-1; j++){
            if(check[j] != check[j+1])
                printf("%d %d\n", check[j], check[j+1]);
                gate++;
        }
        printf("gate = %d\n", gate);
        if(gate == purple)
            beautiful++;*/
        //printf("%d %d %d\n", color[i], color[i+1], color[i+2]);
    }
    printf("%d", beautiful);
}
