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
    vector<vector<string>> v;

    string s;
    while (getline(cin, s)) {
        stringstream ss(s);
        vector<string> t;
        while (ss >> s) t.pb(s);
        v.pb(t);
    }

    vector<int> mxlen;
    for (auto &i : v) for (int j = 0; j < i.size(); j++) {
        if (j == mxlen.size()) mxlen.pb(i[j].size());
        else mxlen[j] = max(mxlen[j], (int)i[j].size());
    }

    for (auto &i : v) for (int j = 0; j < i.size(); j++) cout << i[j] << string((j+1 == i.size() ? 0 : mxlen[j]-i[j].size()), ' ') << " \n"[j+1 == i.size()];
}