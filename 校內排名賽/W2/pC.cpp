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

map<int, vector<string>> mp = {
    {2, {"00", "01", "81"}},
    {4, {"0000", "0001", "2025", "3025", "9801"}},
    {6, {"000000", "000001", "088209", "494209", "998001"}},
    {8, {"00000000", "00000001", "04941729", "07441984", "24502500", "25502500", "52881984", "60481729", "99980001"}}
};

signed main() { WA();
    for (int n; cin >> n;) for (auto i : mp[n]) cout << i << '\n';
}