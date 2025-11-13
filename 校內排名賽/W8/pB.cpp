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
    int ah, am, bh, bm;
    while (cin >> ah >> am >> bh >> bm, ah+am+bh+bm) {
        am += ah*60; bm += bh*60;
        int sum = 0;
        for (int i = am; i != bm && sum < 64*60; i = (i+1)%(24*60), sum++);
        cout << sum << '\n';
    }
}