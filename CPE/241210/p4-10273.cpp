#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define INF 0x3f3f3f3f
#define WA() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define sz(x) ((int)(x).size())
#define int long long

signed main() { WA();
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<vector<int>> v(n);
        for (int i = 0; i < n; i++) {
            int m; cin >> m;
            while (m--) {
                int tmp; cin >> tmp;
                v[i].pb(tmp);
            }
        }

        int lastday = -1, cnt = 0;
        vector<int> kill(n, 0);
        for (int day = 0; day - lastday <= 2520; day++) {
            int mn = INF, cowID = -1;
            for (int i = 0; i < n; i++) {
                if (kill[i]) continue;
                int milk = v[i][day%sz(v[i])];
                if (milk < mn) {
                    mn = milk;
                    cowID = i;
                }
                else if (milk == mn) cowID = -1;
            }
            if (cowID != -1) {
                kill[cowID] = 1;
                lastday = day;
                cnt++;
            }
        }
        cout << n-cnt << ' ' << lastday+1 << '\n';
    }
}