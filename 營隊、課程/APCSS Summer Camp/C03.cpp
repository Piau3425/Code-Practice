#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, q, a, x, y, w;
    cin >> n >> q;
    vector<vector<int>> v(n);
    while (q--) {
        cin >> a;
        if (a == 1) {
            cin >> x >> w;
            v[x-1].push_back(w);
        }
        if (a == 2) {
            cin >> x;
            if(v[x-1].size()) v[x-1].pop_back();
            else cout << "Vector is empty!\n";
        }
        if (a == 3) {
            cin >> x >> y >> w;
            v[x-1].resize(y);
            fill(v[x-1].begin(), v[x-1].end(), w);
        }
    }
    
    for (int i = 0; i < n; i++) {
    	if (v[i].empty()) continue;
        cout << i+1 << ": " << v[i].size() << ' ';
        for (auto val : v[i]) cout << val << ' ';
        cout << '\n';
    }
}