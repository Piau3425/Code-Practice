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
    int t = 0;
    string chr = "ABCDEFGHIJKLMNOPQRSTUVWXYZ123456789";
    string rev = "A   3  HIL JM O   2TUVWXY51SE Z  8 ";
    for (string s; cin >> s;) {
        int flag = 1;
        string r; for (auto &c : s) if (rev[chr.find(c)] != ' ') r.pb(rev[chr.find(c)]); else r.pb(c), flag = 0;
        cout << s;
        if (s != string(s.rbegin(), s.rend()) && flag && r == string(s.rbegin(), s.rend())) cout << " -- is a mirrored string.\n";
        else if (s == string(s.rbegin(), s.rend()) && flag && r == string(s.rbegin(), s.rend())) cout << " -- is a mirrored palindrome.\n";
        else if (s == string(s.rbegin(), s.rend())) cout << " -- is a regular palindrome.\n";
        else cout << " -- is not a palindrome.\n";
        cout << '\n';
    }
}