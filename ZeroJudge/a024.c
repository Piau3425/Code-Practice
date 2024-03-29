#include <stdio.h>

int GCD(int t,int v)
{
    if(t%v==0)
    {
        return v;
    }
    else
    {
        return GCD(v,t%v);
    }
}

int main()
{
    int a, b, temp;
    scanf("%d %d", &a, &b);
    if(a<b)
    {
        temp = a;
        a = b;
        b = temp;
    }
    printf("%d", GCD(a,b));
}



/*int main()
{
    int a, b, x, i, main, A;
    scanf("%d %d", &a, &b);
    if(a < b)
    {
        main = a;
    }
    else
    {
        main = b;
    }
    x = 2;
    A = 1;
    while(x < main)
    {
        if(a % x == 0 && b % x == 0)
        {
            i = 0;
            while(a % x == 0 && b % x == 0)
            {
                a /= x;
                b /= x;
                i++;
            }
            A *= x*i;
        }
        x++;
    }
    printf("%d", A);
}*/
