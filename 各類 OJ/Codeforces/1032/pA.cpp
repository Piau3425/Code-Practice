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
    int t; cin >> t;
    while (t--) {
        int n, s; cin >> n >> s;
        vector<int> v(n);
        for (auto &i : v) cin >> i;
        if (s >= v.front() && s <= v.back()) {
            if (v.back()-s < s-v.front()) cout << (v.back()-s)*2+s-v.front() << '\n';
            else cout << (s-v.front())*2+v.back()-s << '\n';
        }
        else if (s < v.front()) cout << v.back()-s << '\n';
        else cout << s-v.front() << '\n';
    }
}