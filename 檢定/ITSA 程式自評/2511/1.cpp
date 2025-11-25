#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define se second
#define INF LONG_LONG_MAX/1000
#define WA() cin.tie(0)->sync_with_stdio(0)
#define all(x) (x).begin(), (x).end()
#define int long long
#define PII pair<int, int>

signed main() { WA();
    string ans; cin >> ans;
    vector<string> s(3);
    vector<int> v(7);
    for (auto &i : s) cin >> i;
    int n; cin >> n;
    while (n--) {
        string k; cin >> k;
        if (k == ans) v[6]++;
        else {
            int mx = -1e9;
            for (auto &ss : s) for (int i = 0; i <= 6; i++) if (k.substr(i) == ss.substr(i)) mx = max(mx, (int)ss.substr(i).size());
            if (mx != -1e9) v[mx-3]++;
        }
    }
    for (int i = 6; i >= 0; i--) cout << v[i] << " \n"[i == 0];
    cout << v[6]*2000000+v[5]*200000+v[4]*40000+v[3]*10000+v[2]*4000+v[1]*1000+v[0]*200 << '\n';
}