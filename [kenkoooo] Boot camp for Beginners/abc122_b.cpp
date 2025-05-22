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
    string s; cin >> s;
    int mx = 0, cnt = 0;
    for (auto &c : s) if (string("ACGT").find(c) != string::npos) mx = max(++cnt, mx); else cnt = 0;
    cout << mx;
}