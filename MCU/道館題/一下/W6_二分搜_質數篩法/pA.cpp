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
    int n; cin >> n;
    while (n--) {
        int amount, cap; cin >> amount >> cap;
        vector<pair<int, char>> v;
        for (int i = amount; i; i--) {
            string s; cin >> s;
            v.pb({stoi(s.substr(2)), s[0]});
        }

        int l = 0, r = cap+1, ans = -1;
        while (l < r) {
            int mid = l+(r-l)/2;
            if (check(mid)) ans = mid;
        }
    }
}