#include <stdio.h>

int loop, a = 0, b = 0, c = 0, num;

int main() {

    scanf("%d", &loop);

    for(int i = 0; i < loop; i++) {
        scanf("%d", &num);
        switch(num % 3) {
            case 0:
                a++;
                break;
            case 1:
                b++;
                break;
            case 2:
                c++;
                 break;
        }
    }

    printf("%d %d %d", a, b, c);
}
