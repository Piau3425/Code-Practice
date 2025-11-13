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
    string s; 
    while (getline(cin, s)) {
        map<char, char> mp;
        for (char c = 'A'; c <= 'Z'; c++) mp[c] = s[c-'A'];
        int idx = 0;
        getline(cin, s);
        for (auto &c : s) {
            if (!isalpha(c)) continue;
            if (idx == 0 && &c != &s.front()) cout << ' ';
            cout << mp[toupper(c)];
            idx = (idx+1)%5;
        }
        for (int i = 5-idx; i != 5 && i--;) cout << '-';
        cout << '\n';
    }
}