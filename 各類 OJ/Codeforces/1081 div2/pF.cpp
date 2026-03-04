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
#define MAXN 3005

const int MOD = 1e9 + 7;
const int INV[3] = {0, 1, 500000004};

int32_t dpA[MAXN][MAXN], dpB[MAXN][MAXN], dieB[MAXN][MAXN], prefDpA[MAXN][MAXN];
int32_t dpAdj[MAXN * 2][MAXN];

void solve() {
    int n, x, y; cin >> n >> x >> y;
    vector<int> a(n + 2, 0), b(n + 2, 0), prefB(n + 2, 0);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];

    for (int i = 0; i <= n + 1; i++) {
        memset(dpA[i], 0, sizeof(int32_t) * (n + 2));
        memset(dpB[i], 0, sizeof(int32_t) * (n + 2));
        memset(dieB[i], 0, sizeof(int32_t) * (n + 2));
        memset(prefDpA[i], 0, sizeof(int32_t) * (n + 2));
    }
    for (int i = 0; i <= 2 * n + 1; i++) memset(dpAdj[i], 0, sizeof(int32_t) * (n + 2));

    if (x > y) {
        reverse(a.begin() + 1, a.begin() + n + 1);
        reverse(b.begin() + 1, b.begin() + n + 1);
        x = n - x + 1, y = n - y + 1;
    }

    for (int i = 1; i <= n; i++) prefB[i] = prefB[i - 1] + b[i];

    auto getSA = [&](int lA, int rA) { return a[x] + prefB[rA] - prefB[lA - 1] - b[x]; };
    auto getSB = [&](int lB, int rB) { return a[y] + prefB[rB] - prefB[lB - 1] - b[y]; };

    dpA[0][x] = 1;
    for (int t = 0; t <= n; t++) for (int l = 1; l <= x; l++) if (dpA[t][l]) {
        int r = l + t;
        if (r >= y - 1) continue;
        int SA = getSA(l, r), cL = (l > 1) && (SA >= a[l - 1]), cR = (r < n) && (SA >= a[r + 1]);
        if (cL || cR) {
            int prob = 1LL * dpA[t][l] * INV[cL + cR] % MOD;
            if (cL) dpA[t + 1][l - 1] = (dpA[t + 1][l - 1] + prob) % MOD;
            if (cR) dpA[t + 1][l] = (dpA[t + 1][l] + prob) % MOD;
        }
    }

    dpB[0][y] = 1;
    for (int t = 0; t <= n; t++) for (int l = x + 1; l <= y; l++) if (dpB[t][l]) {
        int r = l + t;
        if (r > n) continue;
        if (l <= x + 1) continue;
        int SB = getSB(l, r), cL = (l > 1) && (SB >= a[l - 1]), cR = (r < n) && (SB >= a[r + 1]);
        if (!(cL || cR)) dieB[t + 1][l] = (dieB[t + 1][l] + dpB[t][l]) % MOD;
        else {
            int prob = 1LL * dpB[t][l] * INV[cL + cR] % MOD;
            if (cL) dpB[t + 1][l - 1] = (dpB[t + 1][l - 1] + prob) % MOD;
            if (cR) dpB[t + 1][l] = (dpB[t + 1][l] + prob) % MOD;
        }
    }

    for (int t = 0; t <= n; t++) for (int l = 1; l <= x; l++)
        prefDpA[t][l] = (prefDpA[t][l - 1] + dpA[t][l]) % MOD;

    int ans = 0;

    for (int tB = 1; tB <= n; tB++) for (int lB = x + 1; lB <= y; lB++) if (dieB[tB][lB]) {
        int maxLA = min(x, lB - 2 - tB);
        if (maxLA >= 1) ans = (ans + 1LL * dieB[tB][lB] * prefDpA[tB][maxLA]) % MOD;
    }

    if (x + 1 == y) {
        dpAdj[0][x] = 1;
    } else {
        for (int c = 1; c <= 2 * n; c++) {
            int tA = (c + 1) / 2, tB = c / 2;
            for (int la = 1; la <= x; la++) {
                int ra = la + tA, lb = ra + 1, rb = lb + tB;
                if (ra >= y || rb < y || rb > n) continue;

                if (c % 2 == 1) {
                    if (dpA[tA - 1][la] == 0) continue;
                    int prevSA = getSA(la, ra - 1);
                    if (prevSA >= a[ra]) {
                        bool cL = (la > 1) && (prevSA >= a[la - 1]);
                        int prob = 1LL * dpA[tA - 1][la] * dpB[tB][lb] % MOD * INV[cL + 1] % MOD;
                        dpAdj[c][la] = (dpAdj[c][la] + prob) % MOD;
                    }
                } else {
                    if (dpA[tA][la] == 0) continue;
                    int prevSB = getSB(lb + 1, rb);
                    if (prevSB >= a[lb]) {
                        bool cR = (rb < n) && (prevSB >= a[rb + 1]);
                        int prob = 1LL * dpA[tA][la] * dpB[tB - 1][lb + 1] % MOD * INV[1 + cR] % MOD;
                        dpAdj[c][la] = (dpAdj[c][la] + prob) % MOD;
                    }
                }
            }
        }
    }

    for (int c = 0; c <= 2 * n; c++) {
        for (int la = 1; la <= x; la++) {
            if (!dpAdj[c][la]) continue;
            int tA = (c + 1) / 2, tB = c / 2;
            int ra = la + tA, lb = ra + 1, rb = lb + tB;
            if (rb > n) continue;
            int SA = getSA(la, ra), SB = getSB(lb, rb);

            if (c % 2 == 0) {
                bool cL = (la > 1) && (SA >= a[la - 1]), cR = (SA >= SB);
                if (cL || cR) {
                    int prob = 1LL * dpAdj[c][la] * INV[cL + cR] % MOD;
                    if (cL) dpAdj[c + 1][la - 1] = (dpAdj[c + 1][la - 1] + prob) % MOD;
                    if (cR) ans = (ans + prob) % MOD;
                }
            } else {
                bool cL = (SB >= SA), cR = (rb < n) && (SB >= a[rb + 1]);
                if (!cL && !cR) {
                    ans = (ans + dpAdj[c][la]) % MOD;
                } else {
                    int prob = 1LL * dpAdj[c][la] * INV[cL + cR] % MOD;
                    if (cR) dpAdj[c + 1][la] = (dpAdj[c + 1][la] + prob) % MOD;
                }
            }
        }
    }

    cout << ans << '\n';
}

signed main() { WA();
    for (int t; cin >> t;) while (t--) solve();
}