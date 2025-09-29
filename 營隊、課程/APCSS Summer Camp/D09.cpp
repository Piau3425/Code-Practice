#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, sum = 0;
    cin >> n;
    vector<long long> v(n);
    for (auto &i : v) cin >> i;
    for (auto i : v) sum += i;
    cout << sum;
}