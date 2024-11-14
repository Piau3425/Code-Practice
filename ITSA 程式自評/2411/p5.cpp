#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define se second
#define INF 0x3f3f3f3f
#define WA() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define int long long

signed main() { WA();
    map<string, string> mp = {
        {"01", "East"},
        {"11", "West"},
        {"10", "South"},
        {"00", "North"},
        {"001", " 30 Degrees "},
        {"110", " 45 Degrees "},
        {"100", " 60 Degrees "},
        {"010", " 75 Degrees "},
        {"0100", "250 Miles"},
        {"1100", "700 Miles"},
        {"1010", "550 Miles"},
        {"0110", "100 Miles"}
    };
    int n;
    cin >> n;
    while (n--) {
        string s, tmp;
        cin >> s;
        cout << mp[s.substr(0, 2)] << mp[s.substr(2, 3)] << mp[s.substr(5, 4)] << '\n';
    }
}