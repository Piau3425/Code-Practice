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
    string s;
    set<string> st;
    while (cin >> s) st.insert(s);
    for (auto &a : st) for (int i = 1; i+1 < a.size(); i++) if (st.count(a.substr(0, i)) && st.count(a.substr(i))) {cout << a << '\n'; break;}
}