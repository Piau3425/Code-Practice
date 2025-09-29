#include <bits/stdc++.h>
using namespace std;

#define int long long

struct DSU {
    vector<int> ds, size;
    DSU(int n):ds(n) {
        ds.resize(n);
        size.resize(n);
        for (int i = 0; i < n; i++){
            ds[i] = i;
            size[i] = 1;
        }   
    }

    int find(int x) {
        if (x == ds[x]) return x;
        return ds[x] = find(ds[x]);
    }

    void join(int x, int y) {
        if (find(x) == find(y)) return;
        size[find(x)] += size[find(y)];
        ds[find(y)] = find(x);
    }

    int len(int x) {
        return size[find(x)];
    }
};

signed main() { ios_base::sync_with_stdio(0); cin.tie(0);
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int id = 0;
        string a, b;
        map<string, int> mp;
        DSU d(n*2+5);
        while (n--) {
            cin >> a >> b;
            if (!mp.count(a)) mp[a] = id++;
            if (!mp.count(b)) mp[b] = id++;
            d.join(mp[a], mp[b]);
            cout << d.len(mp[a]) << '\n';
        }
    }
}