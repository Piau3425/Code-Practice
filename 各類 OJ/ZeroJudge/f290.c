//f290. 德潤的大軍

#include <stdio.h>

int n, temp;

int main(){
    scanf("%d", &n);
    int soldier[n][2];

    for(int i = 0; i < n; i++)
        scanf("%d", &soldier[i][0]);

    soldier[0][1] = soldier[0][0];
    soldier[n-1][1] = soldier[n-1][0];
    for(int i = 1; i < n-1; i++)
        soldier[i][1] = soldier[i-1][0] + soldier[i+1][0];

    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n-i-1; j++){
            if(soldier[j][0] > soldier[j+1][0]){
                temp = soldier[j][0];
                soldier[j][0] = soldier[j+1][0];
                soldier[j+1][0] = temp;
                temp = soldier[j][1];
                soldier[j][1] = soldier[j+1][1];
                soldier[j+1][1] = temp;
            }
            else if(soldier[j][0] == soldier[j+1][0] && soldier[j][1] > soldier[j+1][1]){
                temp = soldier[j][0];
                soldier[j][0] = soldier[j+1][0];
                soldier[j+1][0] = temp;
                temp = soldier[j][1];
                soldier[j][1] = soldier[j+1][1];
                soldier[j+1][1] = temp;
            }
        }
    }

    for(int i = 0; i < n; i++)
        printf("%d %d\n", soldier[i][1], soldier[i][0]);
}
