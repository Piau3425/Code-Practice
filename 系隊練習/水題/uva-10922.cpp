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

pair<bool, int> f(string s, int x) {
    if (s.size() < 2) return {!(stoi(s)%9), x};
    int sum = 0;
    for (auto c : s) sum += c-'0';
    if (sum%9) return {0, 0};
    return f(to_string(sum), x+1);
}

signed main() {
    string s;
    while (cin >> s, s != "0") {
        pair<bool, int> ans = f(s, 0);
        cout << s << " is" << (ans.fi ? " " : " not ") << "a multiple of 9";
        if (ans.fi) cout << " and has 9-degree " << ans.se + (ans.se==0);
        cout << ".\n";
    }
}