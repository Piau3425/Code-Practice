#include <stdio.h>

char input[8];

int main(){
    scanf("%s", &input);
    for(int i = 0; i < 6; i++){
        if(input[i] - input[i+1] > 0)
            printf("%d", input[i] - input[i+1]);
        else
            printf("%d", input[i+1] - input[i]);
    }
}
