#include <stdio.h>

int H1, H2, M1, M2, cost, loop, time1, time2;

int main(){
    scanf("%d", &loop);

    for(int i = 0; i < loop; i++){
        scanf("%d %d %d %d %d", &H1, &M1, &H2, &M2, &cost);
        time1 = H1*60+M1;
        time2 = H2*60+M2;
        if(time1+cost <= time2)
            printf("Yes\n");
        else
            printf("No\n");
    }
}
