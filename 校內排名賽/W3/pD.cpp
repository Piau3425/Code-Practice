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

int mx[] = {0, 1, 0, -1}, my[] = {1, 0, -1, 0}, n, m;
vector<int> anc;

inline int getID(int x, int y) {
    return x*m+y;
}

inline int Find(int x) {
    if (!~x) return -1;
    return anc[x] == x ? x : anc[x] = Find(anc[x]);
}

void Union(int a, int b) {
    a = Find(a); b = Find(b);
    if (a > b) swap(a, b);
    if (a != b) anc[b] = a;
}

signed main() { WA();
    int t; cin >> t;
    while (t--) {
        cin >> n >> m;
        vector<tuple<int, int, int>> v(n*m);
        anc.assign(n*m, -1); // 淹沒的點，祖先設為 -1
        for (int i = 0 ; i < n; i++) for (int j = 0; j < m; j++) {
            int x; cin >> x;
            v[getID(i, j)] = {x, i, j};
        }
        sort(all(v), greater<tuple<int, int, int>>());
        int k, sum = 0; cin >> k;
        vector<int> q(k), cnt(k);
        for (auto &i : q) cin >> i;
        for (int i = k-1, j = 0; i >= 0; i--) {
            // i 為當前年份的 index，j 為當前點的 index
            for (; j < n*m && get<0>(v[j]) > q[i]; j++) {
                // 迴圈執行到當前的點高度 > 年份，該條件成立才會沒有被淹沒
                int x = get<1>(v[j]), y = get<2>(v[j]), now = getID(x, y);
                anc[now] = now, sum++; // 該點沒被淹沒時，給予編號
                for (int p = 0; p < 4; p++) {
                    int nx = x+mx[p], ny = y+my[p], nxt = getID(nx, ny);
                    if (nx >= 0 && nx < n && ny >= 0 && ny < m && ~anc[nxt] && Find(now) != Find(nxt)) Union(now, nxt), sum--;
                }
            }
            cnt[i] = sum;
        }

        for (auto &i : cnt) cout << i << ' ';
        cout << '\n';
    }
}