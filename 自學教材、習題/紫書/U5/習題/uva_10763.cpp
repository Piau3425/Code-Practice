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
    int n;
    while (cin >> n, n) {
        set<PII> st;
        int t = n;
        while (n--) {
            int a, b; cin >> a >> b;
            if (a > b) swap(a, b);
            if (st.count({a, b})) st.erase({a, b});
            else st.insert({a, b});
        }

        if (st.empty()) cout << "YES\n";
        else cout << "NO\n";
    }
}