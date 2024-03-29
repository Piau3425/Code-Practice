#include <stdio.h>

int main(){
    int x, a, b, c, d;
    scanf("%d", &x);
    for(int i; x > i; i++){
        scanf("%d %d %d %d", &a, &b, &c, &d);
        if(d - c == c - b){
            printf("%d %d %d %d %d\n", a, b, c, d, d + (d - c));
        }
        else{
            printf("%d %d %d %d %d\n", a, b, c, d, d * (d / c));
        }
    }
}
