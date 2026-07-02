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

int n;
vector<int> used(17);

int p(int x) {
    for (int i = 2; i*i <= x; i++) if (!(x%i)) return false;
    return x >= 2;
}

void dfs(int idx, vector<int> &v) {
    if (idx == n) {
        if (p(v.front()+v.back())) for (auto &i : v) cout << i << " \n"[&i == &v.back()];
        return;
    }
    for (int i = 2; i <= n; i++) {
        if (used[i] || !p(v[idx-1]+i)) continue;
        used[i] = 1; v.pb(i);
        dfs(idx+1, v);
        used[i] = 0; v.pop_back();
    }
}

signed main() { WA();
    for (int t = 0; cin >> n;) { cout << (t ? "\n" : "") << "Case " << ++t << ":\n";
        vector<int> v = {1};
        dfs(1, v);
    }
}