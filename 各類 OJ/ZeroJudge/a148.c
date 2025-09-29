#include <stdio.h>

int main()
{
    int i, a;
    float A;
    while(scanf("%d", &i) != EOF)
    {
        a = A = 0;
        for(int x = 0; i > x ; x++)
        {
            scanf("%d", &a);
            A += a;
        }
        if(A / i > 59)
        {
            printf("no\n");
        }
        else
        {
            printf("yes\n");
        }
    }
}
//i?O?`?? a?O???? A?O????[?`
