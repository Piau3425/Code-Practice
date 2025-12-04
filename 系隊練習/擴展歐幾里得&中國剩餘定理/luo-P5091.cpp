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

int phi(int x) {
    set<int> st;
    int a = x;
    for (int i = 2; i*i <= x; i++) while (!(x%i)) st.insert(i), x /= i;
    if (x > 1) st.insert(x);

    for (auto i : st) a *= (i-1);
    for (auto i : st) a /= i;
    return a;
}

int modpow(int a, int b, int m) {
    int ans = 1;
    a %= m;
    while (b) {
        if (b&1) ans = (ans*a)%m;
        a = (a*a)%m;
        b >>= 1;
    }
    return ans;
}

signed main() { WA();
    int a, m, mb = 0; string sb;
    cin >> a >> m >> sb;
    int phim = phi(m);
    for (auto c : sb) mb = (mb*10+c-'0')%phim;
    if (__gcd(a, m) == 1) cout << modpow(a, mb, m);
    else {
        if (sb.size() <= 8 && stoi(sb) < phi(m)) cout << modpow(a, stoi(sb), m);
        else cout << modpow(a, mb+phim, m);
    }
}