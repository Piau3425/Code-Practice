#include <stdio.h>
#include <string.h>

int main(){
    char a[9999], b[9999];
    int x = 0;
    scanf("%s", &a);
    size_t length = strlen(a);
    for(int i = length - 1; i >= 0; i--){
        b[i] = a[x];
        x++;
    }
    if(strcmp(a, b) == 0){
        printf("yes");
    }
    else{
        printf("no");
    }
}
