#include <bits/stdc++.h>
using namespace std;

vector<int> fn;

int f(int x) {
    int &k = fn[x];
    
    if (~fn[x]) return fn[x];

    if (x <= 1) k = 1;
    else k = f(x-1) + f(x-2);

    return cout << k << ' ', fn[x];
}

int main() {
    int n; cin >> n;
    fn.assign(n+1, -1);
    f(n-1);
}