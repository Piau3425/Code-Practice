#include <stdio.h>

int M, D;

int main(){

    scanf("%d %d", &M, &D);

    switch((M*2+D)%3){
    case 0:
        printf("普通");
        break;
    case 1:
        printf("吉");
        break;
    case 2:
        printf("大吉");
        break;
    }
}
