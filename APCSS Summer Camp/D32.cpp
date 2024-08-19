#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, r;
    cin >> n >> r;
    vector<bool> v(n);
    fill(v.begin(), v.begin() + r, true);

    do {
        bool f = false;
        for (int i = 1; i <= n; i++)
            if (v[i-1]) { cout << (f ? " " : "") << i; f = true; }
        cout << "\n";
    } while (prev_permutation(v.begin(), v.end()));
}