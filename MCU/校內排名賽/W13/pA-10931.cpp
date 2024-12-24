#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define se second
#define INF 0x3f3f3f3f
#define WA() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define int long long

signed main() { WA();
    int n;
    while (cin >> n, n) {
        int cnt = 0;
        string s;
        while (n) s += n%2+'0', cnt += n%2 == 1, n /= 2;
        cout << "The parity of " << string(s.rbegin(), s.rend()) << " is " << cnt << " (mod 2).\n";
    }
}