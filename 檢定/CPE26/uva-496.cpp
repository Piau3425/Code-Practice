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
    for (string a, b; getline(cin, a) && getline(cin, b);) {
        set<int> sa, sb;
        int na, nb;
        stringstream ssa(a); while (ssa >> na) sa.insert(na);
        stringstream ssb(b); while (ssb >> nb) sb.insert(nb);

        int ca, cb; ca = cb = 0;
        for (auto &i : sa) if (sb.count(i)) ca++;
        for (auto &j : sb) if (sa.count(j)) cb++;
        if (sa == sb) cout << "A equals B\n";
        else if (ca == sa.size()) cout << "A is a proper subset of B\n";
        else if (cb == sb.size()) cout << "B is a proper subset of A\n";
        else if (!(ca+cb)) cout << "A and B are disjoint\n";
        else cout << "I'm confused!\n";
    }
}