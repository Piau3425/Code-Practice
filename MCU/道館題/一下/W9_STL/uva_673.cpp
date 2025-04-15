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
    int n; cin >> n; cin.ignore();
    while (n--) {
        string s, l = "([{", r = ")]}";
        stack<char> sta;
        int ck = 1;
        getline(cin, s);
        for (auto c : s) {
            if (l.find(c) != string::npos) sta.push(c);
            else if (sta.size() && l.find(sta.top()) == r.find(c)) sta.pop();
            else ck = 0;
        }
        cout << (ck && sta.empty() ? "Yes\n" : "No\n");
    }
}