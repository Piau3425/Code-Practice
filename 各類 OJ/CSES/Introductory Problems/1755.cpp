#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define se second
#define INF 0x3f3f3f3f
#define WA() cin.tie(0)->sync_with_stdio(0)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define int long long

signed main() { WA();
    string s, t, mid;
    int cnt = 0;
    cin >> s;
    unordered_map<char, int> mp;
    for (auto c : s) mp[c]++;
    for (auto i : mp) if (i.se&1) cnt++, mid = string(i.se, i.fi);
    if (cnt > 1) return cout << "NO SOLUTION", 0;
    for (auto i : mp) if (!(i.se&1)) t += string(i.se/2, i.fi);
    cout << t << mid << string(t.rbegin(), t.rend());
}