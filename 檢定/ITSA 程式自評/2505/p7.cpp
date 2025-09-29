#include <bits/stdc++.h>
using namespace std;

#define WA() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define int long long

signed main() { WA();
    int n; cin >> n;
    deque<int> dq(n);
    for (auto &i : dq) cin >> i;

    int cost = 0, o;
    while (dq.size() > 1) {
        auto k = min_element(all(dq));
        if (k == dq.begin()) o = 1;
        else if (k == prev(dq.end())) o = -1;
        else o = (k[1] < k[-1] ? 1 : -1);
        cost += k[o];
        dq.erase(k);
    }
    cout << cost <<'\n';
}