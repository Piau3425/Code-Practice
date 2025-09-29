#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define se second
#define INF LONG_LONG_MAX/1000
#define WA() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define int long long
#define PII pair<int, int>

signed main() { WA();
    int n, m; cin >> n >> m;
    vector<vector<char>> v(n, vector<char>(m));
    vector<vector<int>> f(n, vector<int>(m));
    string s;
    for (auto &i : v) for (auto &j : i) cin >> j;

    int k, cnt = 0;
    cin >> k;
    while (k--) {
        cin >> s;
        for (auto &i : v) {
            string ns;
            for (auto &c : i) ns += c;
            if (ns.find(s) != string::npos) {
                cnt++;
                fill(f[&i-v.data()].begin()+ns.find(s), f[&i-v.data()].begin()+ns.find(s)+s.size(), 1);
            }
        }

        for (int i = 0; i < m; i++) {
            string ns;
            for (int j = 0; j < n; j++) ns += v[j][i];
            //cout << ns << '\n';
            if (ns.find(s) != string::npos) {
                cnt++;
                for (int j = ns.find(s); j < ns.find(s)+s.size(); j++) f[j][i] = 1;
            }
        }
    }

    cout << cnt << '\n';
    for (auto &i : v) {
        for (auto &j : i) if (f[&i-v.data()][&j-i.data()]) cout << j; else cout << '-';
        cout << '\n';
    }
}