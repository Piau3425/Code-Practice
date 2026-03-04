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

bool tf(string s, int k) {
    int t = 0;
    for (auto c : s) t = (t*10+c-'0')%k;
    return t;
}

void solve(string n) {
    bool isLeap = !tf(n, 4) && tf(n, 100) || !tf(n, 400);
    if (isLeap) cout << "This is leap year.\n";
    if (!tf(n, 15)) cout << "This is huluculu festival year.\n";
    if (isLeap && !tf(n, 55)) cout << "This is bulukulu festival year.\n";
    if (!(isLeap + !tf(n, 15) + (isLeap && !tf(n, 55)))) cout << "This is an ordinary year.\n";
} 

signed main() { WA();
    int t = 0;
    for (string s; cin >> s;) {
        if (t++) cout << '\n';
        solve(s);
    }
}