#include <stdio.h>
#include <math.h>

int main(){
    int a, b, c, A, B, C;
    scanf("%d %d %d", &a, &b, &c);
    C = b*b-4*a*c;
    if(C < 0 || !a) printf("No real root");
    else{
        A = (-b+sqrt(C))/(2*a);
        B = (-b-sqrt(C))/(2*a);
        if (A < B) {
            int tmp = A;
            A = B;
            B = tmp;
        }
        if(A == B) printf("Two same roots x=%d", A);
        else printf("Two different roots x1=%d , x2=%d", A, B);
    }
}