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
    int a, b;
    while (cin >> a >> b, a+b) {
        int cnt = 0;
        for (int i = a; i <= b; i++) cnt += sqrt(i) == (int)sqrt(i) ;
        cout << cnt << '\n';
    }
}