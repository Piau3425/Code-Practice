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
    int n; cin >> n; cin.ignore();
    while (n--) {
        string s; getline(cin, s);
        stringstream ss(s);
        vector<int> v;
        int k, ck = 0;
        while (ss >> k) v.pb(k);
        for (int mask = 0; mask < (1 << v.size()); mask++) {
            int a, b; a = b = 0;
            for (int i = 0; i < v.size(); i++) {
                if (mask & (1 << i)) a += v[i];
                else b += v[i];
            }
            if (a == b) ck = 1;
        }
        ck && (cout << "YES\n") || (cout << "NO\n");
    }
}