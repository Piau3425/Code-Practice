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

string ans;
int n;

void dfs(int now, int l, int r, int len) {
    if (l > n || r > l) return;
    if (now == len) return cout << ans << '\n', void();

    ans += '(';
    dfs(now+1, l+1, r, len);
    ans.pop_back();
    ans += ')';
    dfs(now+1, l, r+1, len);
    ans.pop_back();
}

signed main() {
    for (WA(); cin >> n;) {
        ans.clear();
        dfs(0, 0, 0, n*2);
        cout << '\n';
    }
}