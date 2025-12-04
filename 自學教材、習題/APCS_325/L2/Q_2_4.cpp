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

int c;

int f(int x, int y) {
    if (!y) return 1;
    if (y&1) return f(x, y-1)*x%c;
    int k = f(x, y/2)%c;
    return k*k%c;
}

signed main() { WA();
    string s; int a = 0, b;
    cin >> s >> b >> c;
    for (auto &ch : s) a = (a*10+ch-'0')%c;
    cout << f(a, b)%c;
}