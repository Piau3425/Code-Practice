#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define se second
#define INF LONG_LONG_MAX/1000
#define WA() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define int long long
#define PII pair<int, int>

vector<int> v;
int mx;

void radixsort() {
    for (int pos = 1; pos < pow(10, mx); pos *= 10) {
        vector<vector<int>> bucket(10);
        for (auto &i : v) bucket[i/pos%10].pb(i);
        v.clear();
        for (auto &i : bucket) for (auto &j : i) v.pb(j);
    }
}

signed main() { WA();
    int n;
    while (~scanf("%lld", &n)) {
        v.resize(n);
        for (auto &i : v) scanf("%lld", &i);
        mx = to_string(*max_element(all(v))).size();
        radixsort();
        for (auto &i : v) printf("%lld%c", i, " \n"[&i == &v.back()]);
    }
}