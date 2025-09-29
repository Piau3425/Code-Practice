#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    cout << "Lumberjacks:\n";
    while (n--) {
        bool in = true, d = true;
        vector<int> v(10);
        for (auto &i : v) cin >> i;
        for (int i = 0; i+1 < 10; i++) if (v[i] < v[i+1]) d = false;
        for (int i = 0; i+1 < 10; i++) if (v[i] > v[i+1]) in = false;
        if (in || d) cout << "Ordered\n";
        else cout << "Unordered\n";
    }
}