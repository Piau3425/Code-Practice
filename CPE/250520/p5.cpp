#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a[] = {5, 10, 25, 50};
    vector<int> v(7500, 1);
    for (int k = 0; k < 4; k++) for (int i = a[k]; i < 7500; i++) v[i] += v[i-a[k]];
    while (cin >> n) cout << v[n] << '\n';
}