#include <stdio.h>

int n;

int main(){

    while(scanf("%d", &n) != EOF){
        printf("%d\n", ((n+1)*((n*n)-n+6))/6);
    }

}
