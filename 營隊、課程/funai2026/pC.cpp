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
    string s; getline(cin, s);
    if (s.size() < 11 || s.substr(0, 11) != "CMD:ROTATE_" || s == "CMD:ROTATE_") cout << "Invalid";
    else {
        int t = 0, z = 0;
        for (auto &c : s.substr(11)) {
            if (!isdigit(c)) t = 1;
            if (c == '0') z++;
        } 
        if (t) cout << "Invalid";
        else if (z == s.size()-11) cout << 0;
        else {
            int idx = 11;
            while (s[idx] == '0') idx++;
            while (idx < s.size()) cout << s[idx++];
        }
    }
}