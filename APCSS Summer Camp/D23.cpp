#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &i : v) cin >> i;
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++) cout << v[i] << " \n"[i+1 == v.size()];
    v.erase(unique(v.begin(), v.end()), v.end());
    reverse(v.begin(), v.end());
    for (auto i : v) cout << i << ' ';
}