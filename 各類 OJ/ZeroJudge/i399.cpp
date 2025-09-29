#include <stdio.h>

int dup[9] = {0}, num, max = 1;

int main(){
    for(int i = 0; i < 3; i++){
        scanf("%d", &num);
        dup[num-1] += 1;
    }

    for(int i = 0; i < 9; i++){
        if(dup[i] > 1)
            max = dup[i];
    }
    printf("%d ", max);

    for(int i = 8; i >= 0; i--){
        if(dup[i] >= 1)
            printf("%d ", i+1);
    }
}
