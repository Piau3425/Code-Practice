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

vector<int> anc;

int Find(int x) {
    return x == anc[x] ? x : anc[x] = Find(anc[x]);
}

void Union(int a, int b) {
    a = Find(a), b = Find(b);
    if (a == b) return;
    if (a > b) swap(a, b);
    anc[a] = b;
}

int f(int x) {
    return x >= 201 && x <= 204;
}

int id(string s) {
    if (string("ABCD").find(s[0]) != string::npos) return 201 + s[0]-'A';
    return stoi(s);
}

signed main() { WA();
    int t = 0;
    for (int n; cin >> n;) {
        vector<int> a(n), b(n);
        for (auto &i : a) {
            string s; cin >> s;
            i = id(s);
        }
        for (auto &i : b) {
            string s; cin >> s;
            i = id(s);
        }
        anc.assign(205, 0); iota(all(anc), 0);

        int flag = 1;
        for (int i = 0; i < n; i++) {
            if (f(a[i]) && f(b[i])) {
                if (a[i] != b[i]) flag = 0;
            }
            else Union(a[i], b[i]);
        }

        set<int> st; for (int i = 201; i <= 204; i++) st.insert(Find(i));
        if (t++) cout << '\n';
        if (flag && st.size() == 4) {
            cout << "YES\n";
            for (int i = 1; i <= 200; i++) if (f(Find(i))) cout << i << ' ' << char(Find(i)-201+'A') << '\n';
        }
        else cout << "NO\n";
    }
}