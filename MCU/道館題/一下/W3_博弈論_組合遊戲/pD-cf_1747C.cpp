#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define se second
#define INF LONG_LONG_MAX/1000
#define WA() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define int long long
#define PII pair<int, int>

signed main() { WA();
    int t; cin >> t;
    while (t--) {
        int n, sum = 0; cin >> n;
        vector<int> v(n);
        for (auto &i : v) cin >> i;
        if (v[0] > *min_element(v.begin()+1, v.end())) cout << "Alice\n";
        else cout << "Bob\n";
    }
}