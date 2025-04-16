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
        int r, d, now; cin >> r >> d;
        vector<vector<char>> v(r, vector<char>(r, 'x'));
        if (d == 1) {
            now = r-1;
            for (int i = 0; i < r; i++) v[i][now--] = '*';
        }
        else if (d == 2) {
            now = 0;
            for (int i = 0; i < r; i++) v[i][now++] = '*';
        }
        else if (d == 3) for (int i = 0; i < r; i++) v[i][r-1] = '*';
        else for (int i = 0; i < r; i++) v[i][0] = '*';
        for (auto &i : v) for (auto &j : i) cout << j << " \n"[&j == &i.back()];
    }
}