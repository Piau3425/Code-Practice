#include <iostream>
using namespace std;

int a1, a2, b1, b2, c1, c2, n, x1, x2, sum = -999;

int main(){
    cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2 >> n;

    for(int i = 0; i <= n; i++){
        x1 = i;
        x2 = n-i;
        sum = max(sum, a1*x1*x1+b1*x1+c1 + a2*x2*x2+b2*x2+c2);
    }

    cout << sum;
}
