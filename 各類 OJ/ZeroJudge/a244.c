#include <stdio.h>

int loop;
long a, b, c;

int main(){
    scanf("%d", &loop);
    for(int i = 0; i < loop; i++){
        scanf("%li %li %li", &a, &b, &c);
        switch(a){
            case 1:
                printf("%li\n", b+c);
                break;
            case 2:
                printf("%li\n", b-c);
                break;
            case 3:
                printf("%li\n", b*c);
                break;
            case 4:
                printf("%li\n", b/c);
                break;
            default:
                printf("0");
        }
    }
}
