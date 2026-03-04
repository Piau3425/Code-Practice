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

int isp(int x) {
    for (int i = 2; i*i <= x; i++) if (!(x%i)) return 0;
    return x >= 2;
}

signed main() { WA();
    for (string s, rs; cin >> s;) {
        rs = string(s.rbegin(), s.rend());
        if (isp(stoll(s))) {
            if (s != rs && isp(stoll(rs))) cout << s << " is emirp.\n";
            else cout << s << " is prime.\n";
        }
        else cout << s << " is not prime.\n";
    }
}