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
    string num;
    char c;
    int total = 0;
    while (cin.get(c)) {
        if (isdigit(c)) num += c;
        else if (num.size()) total += stoi(string(num.rbegin(), num.rend())), num.clear();
    }
    if (num.size()) total += stoi(string(num.rbegin(), num.rend()));
    cout << total << '\n';
}