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
    vector<int> p(1000000, 1), ps;
    for (int i = 2; i <= 1000000; i++) {
        if (p[i]) ps.pb(i);
        for (auto j : ps) {
            if (i*j >= p.size()) break;
            p[i*j] = 0;
            if (!(i%j)) break;
        }
    }
    //for (int i = 2; i <= 1000000; i++) if (p[i]) for (int j = i*i; j <= 1000000; j += i) p[j] = 0;

    while (cin >> s) {
        if (p[stoi(s)]) {
            if (p[stoi(string(s.rbegin(), s.rend()))] && s != string(s.rbegin(), s.rend())) cout << s << " is emirp.\n";
            else cout << s << " is prime.\n";
        }
        else cout << s << " is not prime.\n";
    }
}