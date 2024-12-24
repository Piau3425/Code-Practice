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
        if (s.size() == 5) cout << 3 << '\n';
        else {
            int m = 0;
            for (int i = 0; i < 3; i++) m += s[i] == "one"[i];
            if (m < 2) cout << 2 << '\n';
            else cout << 1 << '\n';
        }
    }
}