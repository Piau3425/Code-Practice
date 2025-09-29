#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> v(n), last;
        for (auto &i : v) cin >> i;
        
        int b = 0;
        while (++b) {
            vector<int> g;
            for (int i = 0; i < n; i++) g.push_back(abs(v[i]-v[(i+1)%n]));
            int sum = 0; for (auto &i : g) sum += i;
            if (!sum) {
                cout << "ZERO\n";
                break;
            }
            
            if (b > 100) {
                cout << "LOOP\n";
                break;
            }
            
            v = move(g);
        }
    }
}