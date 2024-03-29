#include <stdio.h>

int flower, add, total;

int main(){
    while(scanf("%d %d", &flower, &add) != EOF){
    for(total = 1; flower > 0; total += add){
        flower -= total;
    }
    if(flower == 0)
        printf("Go Kevin!!");
    else
        printf("No Stop!!");
    }
}
