#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, r;
    cin >> n >> r;
    vector<bool> v(n, 0);
    for (int i = 0; i < r; i++) v[i] = 1;

    do {
        bool f = false;
        for (int i = 0; i < n; i++)
            if (v[i]) { cout << (f ? " " : "") << i+1; f = true; }
        cout << "\n";
    } while (prev_permutation(v.begin(), v.end()));
}