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

void solve() {
    
}

signed main() { WA();
    int x, y, z; cin >> x >> y;
    string s, dir = "N"; cin >> s;
    for (auto &c : s) if (string("NSEWfbFB").find(c) == string::npos) return cout << "Invalid", 0;
    for (auto &c : s) {
        if (string("NSEW").find(c) != string::npos) dir = c;
        else {
            int step = 1;
            if (c == 'b' || c == 'B') step = -1;
            if (c == 'F' || c == 'B') step *= 2;
            if (dir == "N") {
                y += step;
            } else if (dir == "E") {
                x += step;
            } else if (dir == "S") {
                y -= step;
            } else if (dir == "W") {
                x -= step;
            }
        }
    }
    cout << x << ' ' << y;
}