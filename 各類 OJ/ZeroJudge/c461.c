#include <stdio.h>

int a, b, result, and = 0, or = 0, xor = 0;

int main(){

    scanf("%d %d %d", &a, &b, &result);

    if(a != 0 && b != 0)
        and = 1;
    if(a != 0 || b != 0)
        or = 1;
    if(a != 0 || b != 0){
        if(a*b == 0)
            xor = 1;
    }

    if(result == and)
        printf("AND\n");
    if(result == or)
        printf("OR\n");
    if(result == xor)
        printf("XOR\n");
    if(result != and && result != or && result != xor)
        printf("IMPOSSIBLE");
}
