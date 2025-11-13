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
    int n; cin >> n; cin.ignore();
    while (n--) {
        string s, l = "([", r = ")]";
        stack<char> sk;
        int ck = 1;
        getline(cin, s);
        for (auto c : s) {
            if (l.find(c) != string::npos) sk.push(c);
            else if (sk.size() && l.find(sk.top()) == r.find(c)) sk.pop();
            else ck = 0;
        }
        cout << (ck && sk.empty() ? "Yes\n" : "No\n");
    }
}