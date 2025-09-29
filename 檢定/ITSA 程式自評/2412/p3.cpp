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
    string s;
    cin >> n;
    cin.ignore();
    getline(cin, s);
    for (int i = 0; i < s.size(); i += n+1) cout << s[i];
    cout << '\n';
}