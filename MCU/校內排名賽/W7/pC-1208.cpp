#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define se second
#define INF 0x3f3f3f3f
#define WA() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define int long long

vector<int> anc;

int Find(int x) {
    return (anc[x] == x ? x : anc[x] = Find(anc[x]));
}

bool Union(int a, int b) {
    a = Find(a), b = Find(b);
    if (a == b) return false;
    return anc[b] = a, true;
}

signed main() { WA();
    int t;
    cin >> t;
    for (int c = 1; c <= t; c++) {
        int n;
        cin >> n;
        cin.ignore();
        vector<vector<int>> v(n);
        for (int i = 0; i < n; i++) {
            string s;
            int tmp;
            getline(cin, s);
            for (auto &c : s) if (!isalnum(c)) c = ' ';
            stringstream ss(s);
            while (ss >> tmp) v[i].push_back(tmp); 
        }

        vector<tuple<int, int, int>> g;
        for (int i = 0; i+1 < n; i++) for (int j = i+1; j < n; j++) {
            if (v[i][j]) g.push_back({v[i][j], i, j});
        }

        sort(all(g));

        anc.resize(n);
        iota(all(anc), 0);
        printf("Case %d:\n", c);
        for (auto [w, a, b] : g) if (Union(a, b)) printf("%c-%c %d\n", a+'A', b+'A', w);
    }
}