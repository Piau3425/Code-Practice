#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, pfSum = 0;
    cin >> n;
    vector<int> v(n);
    for (auto &i : v) cin >> i;

    for (auto i : v) {
        cout << i - pfSum << ' ';
        pfSum += i - pfSum;
    }
}