#include <stdio.h>

char month[12][10] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
int monthNum;

int main(){
    scanf("%d", &monthNum);

    printf("%s", month[monthNum-1]);
}
