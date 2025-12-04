#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define se second
#define INF LONG_LONG_MAX/1000
#define WA() cin.tie(0)->sync_with_stdio(0)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define int long long
#define PII pair<int, int>

signed main() { WA();
    int r, n;
    while (cin >> r >> n) {
        vector<int> v(n);
        for (auto &i : v) cin >> i;
        priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> pq;
        map<char, string> huff;
        for (int i = 0; i < n; i++) pq.push({v[i], string(1, char('A'+i))});
        while (pq.size() > 1) {
            auto [af, a] = pq.top(); pq.pop(); // 小
            auto [bf, b] = pq.top(); pq.pop(); // 大
            for (auto c : a) huff[c] = '0' + huff[c];
            for (auto c : b) huff[c] = '1' + huff[c];
            pq.push({af+bf, a+b});
        }
        for (int i = 0; i < n; i++) cout << char('A' + i) << ' ' << huff[i+'A'] << '\n';
        cout << '\n';
    }
}