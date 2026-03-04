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

map<char, int> weight = {
    {'*', 3}, {'/', 3},
    {'+', 2}, {'-', 2},
    {'(', 1}
};

void solve() {
    stack<char> sk;
    for (string s; getline(cin, s), s.size();) {
        char c = s[0];
        if (c == '(') sk.push(c);
        else if (c == ')') {
            while (sk.size() && sk.top() != '(') cout << sk.top(), sk.pop();
            sk.pop();
        }
        else if (!isdigit(c)) {
            while (sk.size() && weight[sk.top()] >= weight[c]) cout << sk.top(), sk.pop();
            sk.push(c);
        }
        else cout << c;
    }
    while (sk.size()) cout << sk.top(), sk.pop(); cout << '\n';
}

signed main() { WA();
    int t; for (cin >> t, cin.ignore(), cin.ignore(); t--;) {
        solve();
        if (t) cout << '\n';
    }
}