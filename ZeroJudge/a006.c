#include <stdio.h>
#include <math.h>

int main(){
    int a, b, c, A, B, C; //ax^2 + bx + c
    scanf("%d %d %d", &a, &b, &c);
    A = (b*(-1)+sqrt(pow(b, 2)-4*a*c))/(2*a);
    B = (b*(-1)-sqrt(pow(b, 2)-4*a*c))/(2*a);
    C = pow(b, 2)-4*a*c;
    if(C < 0){
        printf("No real root");
    }
    else if(A == B){
        printf("Two same roots x=%d", A);
    }
    else{
        printf("Two different roots x1=%d , x2=%d", A, B);
    }
}
