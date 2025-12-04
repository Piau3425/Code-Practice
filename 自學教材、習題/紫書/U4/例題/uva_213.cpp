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
    string header;
    while (getline(cin, header)) {
        map<string, char> mp;
        for (int i = 1, idx = 0; header.size() && i <= 7; i++) {
            for (int j = 0; idx < header.size() && j < (1<<i)-1; j++) {
                bitset<32> b(j);
                mp[b.to_string().substr(32-i)] = header[idx++];
            }
        }

        while (1) {
            char c;
            string s;
            for (int i = 3; i; i--) cin >> c, s += c;
            if (s == "000") break;

            int len = stoi(s, 0, 2);
            while (1) {
                s.clear();
                for (int i = len; i; i--) cin >> c, s += c;
                if (s == string(len, '1')) break;
                cout << mp[s];
            }
        }
        cout << '\n';
        cin.ignore();
    }
}