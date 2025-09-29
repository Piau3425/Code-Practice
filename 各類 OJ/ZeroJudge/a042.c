#include <stdio.h>
#include <math.h>

int main()
{
    int a, A;
    while(scanf("%d", &a) != EOF)
    {
        A = pow(a, 2)-a+2;
        printf("%d\n", A);
    }
}
