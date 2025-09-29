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
    string s;
    cin >> s;
    int cnt = 1, mx = 1;
    for (int i = 1; i < s.size(); i++) {
        if (s[i] == s[i-1]) cnt++;
        else cnt = 1;
        mx = max(mx, cnt);
    }
    cout << mx;
}