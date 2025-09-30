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

map<string, int> mp;
int idx = 0;

void gen(string &now, int len) {
    if (now.size() == len) return mp[now] = ++idx, void();
    for (char c = (now.empty() ? 'a' : now.back()+1); c <= 'z'; c++) {
        now += c;
        gen(now, len);
        now.pop_back();
    }
}

signed main() { WA();
    string s;
    for (int i = 1; i <= 5; i++) gen(s, i);
    while (cin >> s) cout << mp[s] << '\n';
}