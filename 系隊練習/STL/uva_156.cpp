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
    map<multiset<char>, int> mp;
    map<multiset<char>, string> restore;
    while (cin >> s, s != "#") {
        multiset<char> st;
        for (auto c : s) st.insert(tolower(c));
        mp[st]++;
        restore[st] = s;
    }

    set<string> ans;
    for (auto &[lst, cnt] : mp) if (cnt == 1) ans.insert(restore[lst]);
    for (auto i : ans) cout << i << '\n';
}