#include <stdio.h>

int input;

int main(){
    scanf("%d", &input);

    while(input > 0){
        printf("%d\n", input);
        input /= 10;
    }
}
