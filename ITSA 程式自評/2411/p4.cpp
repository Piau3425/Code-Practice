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
    while (n--) {
        string s;
        cin >> s;
        int N = 0, S = 0;
        for (auto c : s) N += c-'0';
        for (int i = 1; i < N; i++) if (!(N%i)) S += i;
        if (S < N) cout << N-S << '\n';
        else if (S > N) cout << -1 << '\n';
        else cout << 0 << '\n';
    }
}