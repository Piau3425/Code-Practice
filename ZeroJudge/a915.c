#include <stdio.h>
#include <stdlib.h>

int temp, spotCount;

int main(){
    scanf("%d", &spotCount);
    int spot[spotCount][2];

    for(int i = 0; i < spotCount; i++)
        scanf("%d %d", &spot[i][0], &spot[i][1]);

    for(int i = 0; i < spotCount-1; i++){
        for(int j = 0; j < spotCount-i-1; j++){
            if(spot[j][0] > spot[j+1][0]){
                temp = spot[j][0];
                spot[j][0] = spot[j+1][0];
                spot[j+1][0] = temp;
                temp = spot[j][1];
                spot[j][1] = spot[j+1][1];
                spot[j+1][1] = temp;
            }
            else if(spot[j][0] == spot[j+1][0] && spot[j][1] > spot[j+1][1]){
                temp = spot[j][0];
                spot[j][0] = spot[j+1][0];
                spot[j+1][0] = temp;
                temp = spot[j][1];
                spot[j][1] = spot[j+1][1];
                spot[j+1][1] = temp;
            }
        }
    }

    for(int i = 0; i < spotCount; i++)
        printf("%d %d\n", spot[i][0], spot[i][1]);
}
