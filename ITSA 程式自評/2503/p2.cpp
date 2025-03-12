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
    int n; cin >> n; cin.ignore();
    string s;
    map<string, set<string>> mp;
    vector<pair<string, bool>> v(n);
    for (int i = 0; i < n; i++) {
        string cty; getline(cin, s);
        stringstream ss(s);
        ss >> cty; 
        while (ss >> s) mp[cty].insert(s);
        v[i].fi = cty;
    }

    cin >> n; cin.ignore();
    while (n--) {
        for (auto &i : v) i.se = 0;
        getline(cin, s);
        stringstream ss(s);
        while (getline(ss, s, '+')) {
            stringstream lst(s);
            set<string> st;
            while (lst >> s) st.insert(s);

            for (auto &[cty, isnot] : v) {
                int ck = 1;
                for (auto i : st) if (!mp[cty].count(i)) ck = 0;
                if (ck) isnot = 1;
            }
        }

        int m = 0;
        for (auto i : v) {
            if (i.se) {
                if (m) cout << ' ';
                cout << i.fi, m = 1;
            }
        }
        if (m) cout << "\n";
        else cout << "None\n";
    }
}