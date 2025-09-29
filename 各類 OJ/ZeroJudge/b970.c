#include <stdio.h>

int input;

int main(){
    scanf("%d", &input);
    for(int i = 1; i <= input; i++)
        printf("%d. I don't say swear words!\n", i);
}
