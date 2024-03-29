#include <stdio.h>

int main(){
    double a;
    scanf("%lf", &a);
    printf("%.3lf", (a - 32.0)*5.0/9.0);
}
