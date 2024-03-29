#include <stdio.h>

int main()
{
    int a, x = 1;
    while(scanf("%d", &a))
    {
        if(a == 0){
            break;
        }
        while(x < a)
        {
            if(x % 7 != 0)
            {
                printf("%d ", x);
                x++;
            }
            else
            {
                x++;
            }
        }
        printf("\n");
        x = 1;
    }
}
