#include <stdio.h>

int main(){
    int a;
    scanf("%d", &a);
    if(a <= 10){
        printf("%d", a*6);
    }
    else if(a <= 20){
        printf("%d", 60+(a-10)*2);
    }
    else if(a <= 40){
        printf("%d", 80+(a-20));
    }
    else{
        printf("%d", 100);
    }
}
