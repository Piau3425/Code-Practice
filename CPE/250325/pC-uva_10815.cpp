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
    set<string> st;
    while (cin >> s) {
        for (auto &c : s) {
            if (!isalpha(c)) c = ' ';
            else c = tolower(c);
        }
        stringstream ss(s);
        while (ss >> s) st.insert(s);
    }
    for (auto s : st) cout << s << '\n';
}