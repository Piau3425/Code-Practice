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
    string s; int total = 0;
    while (getline(cin, s)) {
        string now;
        for (auto &c : s) {
            if (isdigit(c)) now += c;
            else if (now.size()) total += stoi(string(now.rbegin(), now.rend())), now.clear();
        }
        if (now.size()) total += stoi(string(now.rbegin(), now.rend()));
    }
    cout << total << '\n';
}