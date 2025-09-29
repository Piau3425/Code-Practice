#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int loop, lengh, width, full;

int main(){
    scanf("%d", &loop);
    for(int j = 0; j < loop; j++){
        scanf("%d %d", &lengh, &width);
        full = lengh*width;
        int *data = malloc(full*sizeof(int)), *dataF = malloc(full*sizeof(int)), trigger = 0;
        memset(data, 0, full);
        memset(dataF, 0, full);

        for(int i = 0; i < full; i++)
            scanf("%d", &data[i]);

        for(int i = 0; i < full; i++)
            dataF[full-i-1] = data[i];

        for(int i = 0; i < full; i++){
            if(data[i] != dataF[i])
                trigger = 1;
        }

        if(trigger)
            printf("keep defending\n");
        else
            printf("go forward\n");

        free(data); free(dataF);
    }
}
