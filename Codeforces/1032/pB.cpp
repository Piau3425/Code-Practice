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

signed main() { WA();
    int t; cin >> t;
    while (t--) {
        int n; string s;
        cin >> n >> s;
        map<char, int> mp;
        for (auto &c : s) mp[c]++;
        string ans = "No\n";
        for (int i = 1; i+1 < n; i++) {
            mp[s[i]]--;
            if (mp[s[i]]) ans = "Yes\n";
        }
        cout << ans;
    }
}