#include <stdio.h>

int main(){
    int a;
    while(scanf("%d", &a) != EOF){
        int A[99], i = 0;
        while(a / 2 != 0){
            A[i] = a % 2;
            a /= 2;
            i++;
        }
        A[i] = a % 2;
        for(; i > -1; i--)
            printf("%d",A[i]);
        printf("\n");
    }
}
