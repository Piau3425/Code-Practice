#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define se second
#define INF LONG_LONG_MAX/1000
#define WA() cin.tie(0)->sync_with_stdio(0)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define int long long
#define PII pair<int, int>

signed main() { WA();
    int n; cin >> n;
    while (n--) {
        int t; cin >> t;
        vector<int> cnt(10);
        for (int i = 1; i <= t; i++) for (auto &c : to_string(i)) cnt[c-'0']++;
        for (auto &i : cnt) cout << i << " \n"[&i == &cnt.back()];
    }
}