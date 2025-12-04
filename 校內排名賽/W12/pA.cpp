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

int f(int x) {
    string s = to_string(x);
    if (s.size() <= 1) return x;
    int sum = 0;
    for (auto &c : s) sum += c-'0';
    return f(sum);
}

signed main() { WA();
    int n; while (cin >> n, n) {
        cout << f(n) << '\n';
    }
}