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
    int n; cin >> n;
    while (n--) {
        string s; cin >> s;
        int len = 0;
        set<string> st;
        do {
            st.clear();
            len++;
            int i = 0;
            for (; i+len-1 < s.size(); i += len) st.insert(s.substr(i, len));
            if (i != s.size()) st.insert(s.substr(i));
        } while (len < s.size() && st.size() != 1);
        cout << len << '\n';
        if (n) cout << '\n';
    }
}