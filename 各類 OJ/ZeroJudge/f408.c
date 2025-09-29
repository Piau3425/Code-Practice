#include <stdio.h>
#include <math.h>

int resident, num, trigger, count = 0;

int main(){
    scanf("%d", &resident);
    int loc[46000] = {[0 ... 45999] = 5};

    for(int i = 0; i < resident; i++){
        scanf("%d", &num);
        if(num < 0){ // 白人是1(原負數)，黑人是0(原正數)
            loc[abs(num)] = 1;
        }
        else
            loc[abs(num)] = 0;
    }

    trigger = loc[0];
    for(int i = 1; i < 1000; i++){
        if(loc[i] == 5)
            continue;
        if(loc[i] != trigger){
            count++;
            trigger = loc[i];
        }
    }

    printf("%d", count-1);
}
