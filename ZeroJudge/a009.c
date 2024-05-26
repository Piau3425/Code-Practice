#include <stdio.h>
int main(){
    char pen[10000];
    fgets(pen,10000,stdin);
    for(int i=0;pen[i] !='\0';i++){
        printf("%c",pen[i]-7);
    }
    return 0;
}