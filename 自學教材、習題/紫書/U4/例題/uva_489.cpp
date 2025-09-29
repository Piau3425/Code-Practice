#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define se second
#define INF LONG_LONG_MAX/1000
#define WA() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define int long long
#define PII pair<int, int>

signed main() { WA();
    int n;
    while (cin >> n, n+1) {
        string a, b;
        cin >> a >> b;
        set<char> st, t, f;
        for (auto &c : a) st.insert(c);
        for (auto &c : b) {
            if (st.count(c)) t.insert(c); else f.insert(c);
            if (f.size() >= 7 || t.size() == st.size()) break;
        }
        cout << "Round " << n << '\n';
        if (t.size() == st.size()) cout << "You win.\n";
        else if (f.size() < 7) cout << "You chickened out.\n";
        else cout << "You lose.\n";
    }
}