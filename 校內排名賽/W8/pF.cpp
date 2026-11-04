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

string sm(string a, string b) {
    vector<int> v(a.size()+b.size());
    for (int i = a.size()-1; i >= 0; i--) {
        for (int j = b.size()-1; j >= 0; j--) {
            v[i+j+1] += (a[i]-'0') * (b[j]-'0');
        }
    }
    for (int i = v.size()-1; i > 0; i--) if (v[i] >= 10) v[i-1] += v[i]/10, v[i]%=10;
    int flag = 0;
    string ret;
    for (auto &i : v) {
        if (!flag && i > 0) flag = 1;
        if (flag) ret.pb(i+'0');
    }
    return ret.size() ? ret : "0";
}

string fpow(string x, int y) {
    string ret = "1";
    for (; y; y>>=1, x = sm(x, x)) if (y&1) ret = sm(ret, x);
    return ret;
}

signed main() { WA();
    string s; int b;
    for (; cin >> s >> b;) {
        int dot = (s.size()-1-s.find('.'))*b;
        s.erase(s.find('.'), 1);
        string ans = fpow(s, b);
        if (ans.size() < dot) ans = string(dot-ans.size(), '0') + ans;
        ans.insert(ans.size()-dot, ".");
        while (ans.back() == '0') ans.pop_back();
        cout << ans << '\n';
    }
}