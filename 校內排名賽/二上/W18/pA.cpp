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

void solve(string s) {
    multiset<char> st;
    set<char> stt;
    int mx = -1e9;
    for (auto c : s) if (isalpha(c)) st.insert(c), stt.insert(c), mx = max(mx, (int)st.count(c));
    for (auto i : stt) if (st.count(i) == mx) cout << i;
    cout << ' ' << mx << '\n';
}

signed main() { WA();
    for (string s; getline(cin, s);) {
        solve(s);
    }
}