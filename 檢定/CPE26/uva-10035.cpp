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
#define TIII tuple<int, int, int>

template<typename T>
using rbtree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

signed main() { WA();
    for (string a, b; cin >> a >> b, a != "0" || b != "0";) {
        if (a.size() > b.size()) swap(a, b);
        int i = a.size()-1, j = b.size()-1, cnt = 0;
        for (; j >= 0; i--, j--) {
            if (i >= 0) b[j] += a[i]-'0';
            if (b[j]-'0' >= 10) {
                b[j]-=10;
                if (j-1 >= 0) b[j-1]++;
                cnt++;
            }
        }
        if (cnt) cout << cnt;
        else cout << "No";
        cout << " carry operation";
        if (cnt > 1) cout << "s.\n";
        else cout << ".\n";
    }
}