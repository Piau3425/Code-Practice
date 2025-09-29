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
    int n; cin >> n;
    while (n--) {
        map<char, int> mp;
        string s; cin >> s;
        for (auto i : s) mp[i]++;
        if (s.size() != 4) cout << "Failure Input\n";
        else {
            string ans;
            for (auto i : mp) ans += to_string(i.se);
            sort(all(ans));
            if (ans == "112") cout << "Yes\n";
            else cout << "No\n";
        }
    }
}