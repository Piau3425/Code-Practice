#include <iostream>
using namespace std;

int n, i, sum = 0;

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        printf("+%d", i);
        sum = sum + i;
    }
    printf("= %d", sum);
}