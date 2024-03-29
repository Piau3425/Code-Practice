#include <stdio.h>
#include <string.h>

int main(){
    char a[100], b[100];
    int x = 0;
    scanf("%s", &a);
    size_t length = strlen(a);

    while(a[length-1] == 48){
        length--;
    }
    if(length == 0)
        printf("0");
    else{
        for(int i = length - 1; i >= 0; i--){
            b[i] = a[x];
            x++;
        }
    printf("%s", b);
    }
}
