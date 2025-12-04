#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define se second
#define INF 0x3f3f3f3f
#define WA() cin.tie(0)->sync_with_stdio(0)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define int long long

signed main() { WA();
    int n;
    string s;
    cin >> n;
    cin.ignore();
    getline(cin, s);
    for (int i = 0; i < s.size(); i += n+1) cout << s[i];
    cout << '\n';
}