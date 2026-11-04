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

int siz;

struct Node {
    int son[52], fail;
    vector<int> id;
    Node(): fail(0) {
        memset(son, 0, sizeof(son));
        id.clear();
    }
} tr[1000005];

int getid(char c) {
    if ('a' <= c && c <= 'z') return c - 'a';
    return c - 'A' + 26;
}

void insert(string s, int id) {
    int p = 0;
    for (auto ch : s) {
        int c = getid(ch);
        if (!tr[p].son[c]) tr[p].son[c] = ++siz;
        p = tr[p].son[c];
    }
    tr[p].id.push_back(id);
}

void build() {
    queue<int> q;
    for (int i = 0; i < 52; i++) if (tr[0].son[i]) q.push(tr[0].son[i]);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int i = 0; i < 52; i++) {
            if (tr[u].son[i]) {
                tr[tr[u].son[i]].fail = tr[tr[u].fail].son[i];
                q.push(tr[u].son[i]);
            }
            else tr[u].son[i] = tr[tr[u].fail].son[i];
        }
    }
}

void query(string s, vector<int> &ans) {
	int u = 0;
	for (auto ch : s) {
		u = tr[u].son[getid(ch)];
		for (int j = u; j; j = tr[j].fail) for (int id : tr[j].id) ans[id] = true;
    }
}

void init() {
    for (int i = 0; i <= siz; i++) tr[i] = Node();
    siz = 0;
}

signed main() { WA();
    int t; for (cin >> t; t--;) {
        init();
        int l, c, w; cin >> l >> c >> w;
        vector<int> v(l);
        for (auto &i : v) cin >> i;
        
        int n; cin >> n;
        vector<int> ans(n);
        for (int i = 0; i < n; i++) cin >> t, insert(t, i);
        build(); query(s, ans);
        for (auto &i : ans) if (i) cout << "y\n"; else cout << "n\n";
    }
}