#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define se second
#define INF LONG_LONG_MAX/1000
#define WA() cin.tie(0)->sync_with_stdio(0)
#define all(x) (x).begin(), (x).end()
#define int long long
#define PII pair<int, int>

signed main() { WA();
    int x, n;  cin >> x >> n;
    set<int> st; multiset<int> dis; dis.insert(x); st.insert(0); st.insert(x);
    for (; n--;) {
        int k; cin >> k;
        auto it = st.upper_bound(k);
        dis.erase(dis.find(*it-*(prev(it))));
        dis.insert(k-*prev(it));
        dis.insert(*it-k);
        st.insert(k);
        cout << *prev(dis.end()) << '\n';
    }
}