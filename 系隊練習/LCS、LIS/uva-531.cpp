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
        string s;
        while (cin >> s) {
            vector<string> a, b;
            a.pb(s);
            while (cin >> s, s != "#") a.pb(s);
            while (cin >> s, s != "#") b.pb(s);
            vector<vector<int>> v(a.size()+1, vector<int>(b.size()+1));
            for (int i = 1; i <= a.size(); i++) {
                for (int j = 1; j <= b.size(); j++) {
                    if (a[i-1] == b[j-1]) v[i][j] = v[i-1][j-1]+1;
                    else v[i][j] = max(v[i-1][j], v[i][j-1]);
                }
            }

            int i = a.size(), j = b.size();
            vector<string> g;
            while (1) {
                if (!i || !j) break;
                if (a[i-1] == b[j-1]) {
                    g.pb(a[i-1]);
                    i--, j--;
                }
                else if (v[i][j] == v[i][j-1]) j--;
                else i--;
            }
            reverse(all(g));
            for (auto &s : g) cout << s << " \n"[s.data() == g.back().data()];
        }
    }
