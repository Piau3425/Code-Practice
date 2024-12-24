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
    cin >> n;
    if ((n*(n+1)/2) & 1) cout << "NO\n";
    else {
        vector<int> a, b;
        int sum = 0;
        for (int i = n; i > 0; i--) {
            //cout << sa << ' ' << sb << ' ' << i << '\n';
            if (sum + i <= n*(n+1)/2/2) sum += i, a.pb(i);
            else b.pb(i);
        }
        cout << "YES\n" << sz(a) << '\n';
        for (auto i : a) cout << i << ' ';
        cout << '\n' << sz(b) << '\n';
        for (auto i : b) cout << i << ' ';
        cout << '\n';
    }
}