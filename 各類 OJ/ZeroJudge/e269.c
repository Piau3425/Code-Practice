#include <stdio.h>

char input[30], trans[30], x = 1;

int main(){
    while(scanf("%s", &input) != EOF){
        trans[x-1] = input[x-1];
        x++;
    }
    printf("%s", trans);
}
