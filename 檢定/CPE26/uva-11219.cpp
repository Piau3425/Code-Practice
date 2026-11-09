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
    int t = 1, T; for (cin >> T; t <= T; t++) { cout << "Case #" << t << ": ";
        int d1, d2, m1, m2, y1, y2; char c;
        cin >> d1 >> c >> m1 >> c >> y1;
        cin >> d2 >> c >> m2 >> c >> y2;
        int age = y1-y2-(tie(m1, d1) < tie(m2, d2));
        if (age > 130) cout << "Check birth date\n";
        else if (tie(y1, m1, d1) < tie(y2, m2, d2)) cout << "Invalid birth date\n";
        else cout << age << '\n';
    }
}