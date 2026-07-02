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
    int t = 1, n, T; for (cin >> T; t <= T; t++) {
        cin >> n;
        cout << "Case #" << t << ": " << n;
        set<int> st;
        while (!st.count(n)) {
            st.insert(n);
            int sum = 0;
            for (auto c : to_string(n)) sum += (c-'0')*(c-'0');
            n = sum;
        }
        if (n == 1) cout << " is a Happy number.\n";
        else cout << " is an Unhappy number.\n";
    }
}