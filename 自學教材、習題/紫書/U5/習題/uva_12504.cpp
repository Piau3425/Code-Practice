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
    int t; cin >> t; cin.ignore();
    while (t--) {
        string a, b;
        getline(cin, a); getline(cin, b);
        a = a.substr(1, a.size()-2);
        b = b.substr(1, b.size()-2);
        map<string, string> ma, mb;
        stringstream sa(a), sb(b);
        while (getline(sa, a, ',')) ma[a.substr(0, a.find(':'))] = a.substr(a.find(':')+1);
        while (getline(sb, b, ',')) mb[b.substr(0, b.find(':'))] = b.substr(b.find(':')+1);
        vector<string> add, sub, mul;
        for (auto &i : ma) if (mb.count(i.fi)) {
            if (mb[i.fi] != i.se) mul.pb(i.fi);
        }
        else sub.pb(i.fi);
        for (auto &i : mb) if (!ma.count(i.fi)) add.pb(i.fi);
        if (add.empty() && sub.empty() && mul.empty()) cout << "No changes\n";
        if (add.size()) cout << '+'; for (auto &i : add) cout << i << ",\n"[&i == &add.back()];
        if (sub.size()) cout << '-'; for (auto &i : sub) cout << i << ",\n"[&i == &sub.back()];
        if (mul.size()) cout << '*'; for (auto &i : mul) cout << i << ",\n"[&i == &mul.back()];
        cout << '\n';
    }
}