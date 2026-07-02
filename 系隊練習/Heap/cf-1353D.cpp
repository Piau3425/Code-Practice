#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define se second
#define INF LONG_LONG_MAX/1000
#define WA() cin.tie(0)->sync_with_stdio(0)
#define all(x) (x).begin(), (x).end()
#define int long long
#define TIII tuple<int, int, int>

signed main() { WA();
    int t; for (cin >> t; t--;) {
        priority_queue<TIII> pq;
        int n; cin >> n;
        vector<int> v(n);
        pq.push({n, -1, n});
        for (int i = 1; i <= n; i++) {
            auto [len, l, r] = pq.top(); pq.pop();
            l *= -1;
            int mid;
            if ((r-l+1)&1) mid = (l+r)/2;
            else mid = (l+r-1)/2;
            v[mid-1] = i;
            pq.push({mid-l, -l, mid-1});
            pq.push({r-mid, -(mid+1), r});
        }
        for (auto &i : v) cout << i << " \n"[&i == &v.back()];
    }
}