#include <iostream>
using namespace std;

int F(int a){
    if(a == 1)
        return 1;
    else if(!(a & 1))
        return F(a/2);
    else
        return F(a-1) + F(a+1);
}

int main(){
    int x;
    cin >> x;
    cout << F(x);
}