#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define se second
#define INF LONG_LONG_MAX/1000
#define WA() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define int long long
#define PII pair<int, int>

signed main() { WA();
    string s;
    while (cin >> s) {
        stack<char> sk;
        int ck = 1;
        for (auto &c : s) {
            if (string("([{").find(c) != string::npos) sk.push(c);
            else if (sk.size() && string("([{").find(sk.top()) == string(")]}").find(c)) sk.pop();
            else {
                ck = 0;
                break;
            }
        }
        if (ck && sk.empty()) cout << "yes\n";
        else cout << "no\n";
    }
}