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
    int n; for (cin >> n; n--;) {
        int sum = 0;
        for (int k = 4; k--;) {
            string s; cin >> s;
            for (auto &c : s) {
                if ((&c-s.data())&1) sum += c-'0';
                else for (auto &c : to_string((c-'0')*2)) sum += c-'0';
            }
        }
        if (sum%10) cout << "Invalid\n";
        else cout << "Valid\n";
    }
}