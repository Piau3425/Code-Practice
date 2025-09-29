#include <iostream>
#include <cmath>
using namespace std;

int main(){
    string as, bs;
    long long a = 0, b = 0;
    cin >> as >> bs;

    for(int i = 0; i < as.length(); i++)
        a += (as[i] - 'A' + 1) * pow(26, as.length() - 1 - i);
    
    for(int i = 0; i < bs.length(); i++)
        b += (bs[i] - 'A' + 1) * pow(26, bs.length() - i - 1);
    
    cout << abs(a - b) + 1;
}