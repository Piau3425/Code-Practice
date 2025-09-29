#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &i : v) cin >> i;
    reverse(v.begin(), v.end());
    for (auto i : v) cout << i << ' ';
}