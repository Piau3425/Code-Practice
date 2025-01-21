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
    int n; cin >> n;

    while (n--) {
        string s; cin >> s;
        int sum = 0, i = 1;
        for (auto &c : s) if (c == 'O') sum += i++; else i = 1;
        cout << sum << '\n';
    }
}