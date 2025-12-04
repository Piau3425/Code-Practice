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
    int n;
    string s;
    while (cin >> n, n) {
        cin.ignore();
        while (getline(cin, s), s != "0") {
            stringstream ss(s);
            stack<int> sta;
            int now; ss >> now;
            for (int i = 1; i <= n; i++) {
                sta.push(i);
                while (sta.size() && sta.top() == now) sta.pop(), ss>>now;
            }

            if (sta.empty()) cout << "Yes\n";
            else cout << "No\n";
        }
        cout << '\n';
    }
}