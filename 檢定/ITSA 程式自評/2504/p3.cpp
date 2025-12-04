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
    int n; cin >> n; cin.ignore();
    while (n--) {
        string a, b;
        vector<string> va, vb;
        getline(cin, a); getline(cin, b);
        for (auto &c : a) if (!isalpha(c)) c = ' ';
        for (auto &c : b) if (!isalpha(c)) c = ' ';
        stringstream aa(a), bb(b);
        while (aa >> a) {
            bb >> b;
            if (a != b) {
                va.pb(a);
                vb.pb(b);
            }
        }

        vector<string> ans;
        for (int i = 0; i < va.size(); i++) {
            if (i&1) ans.pb(vb[i]);
            else ans.pb(va[i]);
        }
        for (auto &i : ans) cout << i << " \n"[&i == &ans.back()];
    }
}