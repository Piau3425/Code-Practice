#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    double sum;
    vector<int> v(n);
    for (auto &i : v) cin >> i;
    for (auto i : v) sum += i;
    cout << fixed << setprecision(3) << sum/n;
}