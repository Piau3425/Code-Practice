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
    int n, ck; cin >> n; cin.ignore();
    string s, k;
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
            for (auto &[cty, isnot] : v) {
                ck = 1;
                stringstream lst(s); 
                while (lst >> k) !mp[cty].count(k) && (ck = 0);
                ck && (isnot = 1);
            }
        }

        ck = 0;
        for (auto [cty, isnot] : v) isnot && cout << (ck++ ? " " : "") << cty;
        (ck && cout << "\n") || cout << "None\n";
    }
}