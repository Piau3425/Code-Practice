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
    int len, n; cin >> len >> n;
    vector<int> v(n);
    set<int> st;
    map<int, int> mp;
    int now = 0, cnt = 0;
    for (auto &i : v) cin >> i, st.insert(i);
    for (int l = 0, r = 0; r < n; r++) {
        if (++mp[v[r]] == 1) now++;
        while (mp[v[l]] > 1) {
            mp[v[l]]--;
            l++;
        }
        if (now == st.size() && r-l+1 == len) cnt++;
    }
    cout << cnt;
}