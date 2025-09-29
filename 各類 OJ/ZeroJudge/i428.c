#include <stdio.h>
#include <stdio.h>

int stop, disSum = 0;

int main(){
    scanf("%d", &stop);
    scanf("%d %d", &x1, &y1)

    for(int i = 0; i < stop-1; i++){
        scanf("%d %d", &x2, &y2);

        disSum += fabs(x1 - x2);
    }
}
