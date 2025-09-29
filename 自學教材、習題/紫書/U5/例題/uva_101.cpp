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

vector<vector<int>> v;

pair<int, int> find(int x) {
    for (auto &i : v) for (auto &j : i) if (j == x) return {&i-v.data(), &j-i.data()};
}

void cle(int p, int h) {
    for (int i = v[p].size()-1; i > h; i--) {
        v[v[p].back()].pb(v[p].back());
        v[p].pop_back();
    }
}

void move(int pA, int pB, int h) {
    int i = h;
    for (; i < v[pA].size(); i++) v[pB].pb(v[pA][i]);
    while (i > h) v[pA].pop_back(), i--;
}

signed main() { WA();
    int n; cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++) v[i].pb(i);
    string cmd, cmd2;
    while (cin >> cmd, cmd != "quit") {
        int a, b;
        cin >> a >> cmd2 >> b;
        auto [pA, hA] = find(a);
        auto [pB, hB] = find(b);
        if (pA == pB) continue;

        if (cmd == "move") cle(pA, hA);
        if (cmd2 == "onto") cle(pB, hB);
        move(pA, pB, hA);
    }

    for (int i = 0; i < n; i++) {
        cout << i << ":";
        for (auto i : v[i]) cout << ' ' << i;
        cout << '\n';
    }
}