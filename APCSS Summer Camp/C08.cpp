#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &i : v) cin >> i;
    for (int i = n-2; i >= 0; i--) while (v[i] <= v[i+1]) v[i]++;
    for (auto i : v) cout << i << ' ';
}