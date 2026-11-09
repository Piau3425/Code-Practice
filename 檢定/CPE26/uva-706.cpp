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
    int s; string n;
    vector<string> H = {"- -- -----", "  ----- --", "- -- -- --"}, L = {"|   ||| ||", "| |   | | "}, R = {"|||||  |||", "|| |||||||"};
    while (cin >> s >> n && s) {
        for (int k = 0; k < 3; k++) {
            for (int i = 0; i < n.size(); i++)
                cout << (i ? " " : "") << ' ' << string(s, H[k][n[i]-'0']) << ' ';
            cout << '\n';
            for (int r = 0; k < 2 && r < s; r++, cout << '\n')
                for (int i = 0; i < n.size(); i++)
                    cout << (i ? " " : "") << L[k][n[i]-'0'] << string(s, ' ') << R[k][n[i]-'0'];
        }
        cout << '\n';
    }
}