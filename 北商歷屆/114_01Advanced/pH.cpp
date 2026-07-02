#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define pb push_back
#define fi first
#define se second
#define INF LONG_LONG_MAX/1000
#define WA() cin.tie(0)->sync_with_stdio(0)
#define all(x) (x).begin(), (x).end()
#define int long long
#define PII pair<int, int>

template<typename T>
using rbtree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

signed main() { WA();
    for (int n; cin >> n, n;) {
        int sum = !(n==1);
        for (int i = 2; i*i <= n; i++) if (!(n%i)) sum += i + (n/i==i ? 0 : n/i);
        cout << setw(5) << n;
        if (sum == n) cout << "  PERFECT\n";
        else if (sum > n) cout << "  ABUNDANT\n";
        else cout << "  DEFICIENT\n";
    }
}