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

const int MAXN = 524288 + 5;
vector<int> minPrime(MAXN, 0), primes;

void init() {
    for (int i = 2; i < MAXN; i++) {
        if (!minPrime[i]) minPrime[i] = i, primes.pb(i);
        for (int p : primes) {
            if (i * p >= MAXN) break;
            minPrime[i * p] = p;
            if (i % p == 0) break;
        }
    }
}

signed main() { WA();
    init();

    int t; for (cin >> t; t--;) {
        int n, m; cin >> n >> m;
        int N = 1; while (N <= m) N <<= 1;

        vector<int> req(N, 1);
        int tmpN = n;
        for (int i = 2; i * i <= tmpN; i++) if (tmpN % i == 0) {
            int cnt = 0; while (tmpN % i == 0) cnt++, tmpN /= i;
            if (i < N) req[i] = cnt + 1;
        }
        if (tmpN > 1 && tmpN < N) req[tmpN] = 2;

        vector<int> C(N, 0); C[1] = 1;
        for (int i = 2; i < N; i++) {
            int p = minPrime[i], tmp = i, cnt = 0;
            while (tmp % p == 0) cnt++, tmp /= p;
            if (cnt == req[p]) C[i] = -C[tmp];
        }

        vector<PII> ivs;
        for (int bit = 19, cur = 0; ~bit; bit--) if ((m + 1) & (1LL << bit)) {
            ivs.pb({cur, bit});
            cur |= (1LL << bit);
        }

        int ans = 0;
        vector<PII> evt; evt.reserve(10000000);

        for (int l = 1; l < N; l++) if (C[l]) {
            evt.clear();
            for (int x = 0; x < N; x += l) for (auto &[base, bit] : ivs) {
                int nb = base ^ (x & ~((1LL << bit) - 1));
                int L = max(0LL, nb), R = min(m, nb + (1LL << bit) - 1);
                if (L <= R) evt.pb({L, 1}), evt.pb({R + 1, -1});
            }

            sort(all(evt));
            int cv, lx, sumSq; cv = lx = sumSq = 0;
            for (int i = 0; i < (int)evt.size();) {
                int nx = evt[i].fi;
                if (nx > lx) sumSq += (nx - lx) * cv * cv, lx = nx;
                while (i < (int)evt.size() && evt[i].fi == nx) cv += evt[i].se, i++;
            }
            ans += C[l] * sumSq;
        }
        cout << ans << "\n";
    }
}