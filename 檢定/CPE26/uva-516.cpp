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

int p(int x, int k) {
    int ret = 1;
    for (; k; k>>=1, x*=x) if (k&1) ret *= x;
    return ret;
}

int isp(int x) {
    for (int i = 2; i*i <= x; i++) if (!(x%i)) return false;
    return x >= 2;
}

signed main() { WA();
    for (string s; getline(cin, s), s != "0";) {
        stringstream ss(s);
        int sum = 1;
        int a, b; while (ss >> a) {
            ss >> b;
            sum *= p(a, b);
        }
        sum--;
        int flag = 0;
        for (int i = sum; sum > 1 && i > 0; i--) {
            if (isp(i)) {
                int cnt = 0;
                while (!(sum%i)) cnt++, sum/=i;
                if (cnt) {
                    if (flag) cout << ' ';
                    cout << i << ' ' << cnt;
                    flag = 1;
                }
            }
        }
        cout << '\n';
    }
}