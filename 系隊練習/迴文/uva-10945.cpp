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
    for (string s; getline(cin, s), s != "DONE";) {
        string all;
        for (stringstream ss(s); ss >> s; all += s);
        all.erase(remove_if(all(all), [](char c){ return ispunct(c); }), all.end());
        for (auto &c : all) c = tolower(c);
        if (all == string(all.rbegin(), all.rend())) cout << "You won't be eaten!\n";
        else cout << "Uh oh..\n";
    }
}