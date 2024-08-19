#include <iostream>
using namespace std;

int f91(int x){
    if(x <= 100)
        return f91(f91(x+11));
    else if(x >= 101)
        return x-10;
}

int main(){
    int n;
    while(1){
        cin >> n;
        if(n == 0)
            break;
        printf("f91(%d) = %d\n", n, f91(n));
    }
}
