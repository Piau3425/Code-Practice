#include <stdio.h>

int loop, tmp;

int main(){
    while(scanf("%d", &loop) != EOF){
        int ary[loop];

        for(int i = 0; i < loop; i++)
            scanf("%d", &ary[i]);

        for(int i = 0; i < loop; i++){
            for(int j = 0; j < loop-1; j++){
                if(ary[j]%10 > ary[j+1]%10){
                    tmp = ary[j];
                    ary[j] = ary[j+1];
                    ary[j+1] = tmp;
                }
                else if(ary[j]%10 == ary[j+1]%10){
                    if(ary[j] < ary[j+1]){
                    tmp = ary[j];
                    ary[j] = ary[j+1];
                    ary[j+1] = tmp;
                    }
                }
            }
        }

        for(int i = 0; i < loop; i++){
        printf("%d ", ary[i]);
        }
        printf("\n");
    }
}
