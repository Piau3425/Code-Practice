#include <stdio.h>

int loop, dir, x = 0, y = 0, n;

int main(){
    scanf("%d", &loop);
    for(int i = 0; i < loop; i++){
        scanf("%d %d", &dir, &n);
        switch(dir){
            case 0:
                y += n;
                break;
            case 1:
                x += n;
                break;
            case 2:
                y -= n;
                break;
            case 3:
                x -= n;
                break;
        }
    }
    printf("%d %d", x, y);
}
