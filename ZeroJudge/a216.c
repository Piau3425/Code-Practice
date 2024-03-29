#include <stdio.h>

long ans;
long f(long n);
long g(long n);

int main(){
    while(scanf("%li", &ans) != EOF){
        printf("%li %li\n", f(ans), g(ans));
    }
}


long f(long n){
    if(n == 1)
        return 1;
    n += f(n-1);
    return n;
}

long g(long n){
    if(n == 1)
        return 1;
    n = f(n) + g(n-1);
    return n;
}
