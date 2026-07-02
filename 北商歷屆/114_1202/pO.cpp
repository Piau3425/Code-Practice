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

int f(int x) {
    for (int i = 2; i*i <= x; i++) if (!(x%i)) return false;
    return x >= 2;
}

signed main() { WA();
    int t; for (cin >> t; t--;) {
        int n; cin >> n; cout << n << " ";
        string s = to_string(n); reverse(all(s));
        if (f(n)) {
            if (n != stoi(s) && f(stoi(s))) cout << "is an emirp number.\n";
            else cout << "is a prime number.\n";
        }
        else cout << "is not a prime number.\n";
    }
}