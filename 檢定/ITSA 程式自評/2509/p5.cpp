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
    int n; cin >> n; cin.ignore();
    string s;
    while (getline(cin, s)) {
        stringstream ss(s);
        vector<int> v, ans = {1, 2, 4, 6, 5, 3};
        while (getline(ss, s, ',')) v.pb(stoi(s));
        int cnt = 0;
        while (v != ans) {
            if (v < ans) next_permutation(all(v));
            else prev_permutation(all(v));
            cnt++;
        }
        cout << cnt+1 << '\n';
    }
}