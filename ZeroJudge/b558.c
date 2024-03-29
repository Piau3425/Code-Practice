#include <stdio.h>

int n, sum;

int main(){
    while(scanf("%d", &n) != EOF){
        int sum = 1;

        for(int i = 0; i < n; i++){
            sum += i;
        }

        printf("%d\n", sum);
    }
}
