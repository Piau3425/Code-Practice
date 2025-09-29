#include <bits/stdc++.h>
using namespace std;

int main(){
    long long a[3];
    for (auto &i : a) cin >> i;
    sort(a, a+3);
    cout << a[2] - a[0];
}