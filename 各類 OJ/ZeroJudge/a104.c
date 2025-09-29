#include <stdio.h>

int loop, temp, ary[9999];

main(){
    while(scanf("%d", &loop) != EOF){
        for(int i = 0; i < loop; i++){
            scanf("%d", &ary[i]);
        }
        for(int i = 0; i < loop - 1; i++){
            for(int j = 0; j < loop - (1+i); j++){
                if(ary[j] > ary[j+1]){
                    temp = ary[j];
                    ary[j] = ary[j+1];
                    ary[j+1] = temp;
                }
            }
        }
        for(int i = 0; i < loop; i++){
            printf("%d", ary[i]);
            if(i >= loop)
                break;
            printf(" ");
        }
        printf("\n");
    }
}
