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
#define MAXN 10000001

bool Prime(int x) {
    for (int i = 2; i*i <= x; i++) if (!(x%i)) return false;
    return true;
}

signed main() { WA();
    vector<int> isp(MAXN, 1), ps;
    vector<int> pre(10004);
    for (int i = 0; i <= 10004; i++) pre[i] = Prime(i*i+i+41);
    int a, b;
    while (cin >> a >> b) {
        double cnt = 0;
        for (int i = a; i <= b; i++) cnt += pre[i];
        cout << fixed << setprecision(2) << 100.0*cnt/(b-a+1)+0.0000001 << '\n';
    }
}