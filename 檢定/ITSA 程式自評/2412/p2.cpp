#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define se second
#define INF 0x3f3f3f3f
#define WA() cin.tie(0)->sync_with_stdio(0)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define int long long

signed main() { WA();
    map<pair<string, string>, map<string, int>> mp = {
        {{"O", "O"}, {{"O", 100}}},
        {{"A", "O"}, {{"A", 50}, {"O", 50}}},
        {{"O", "S"}, {{"S", 50}, {"O", 50}}},
        {{"AS", "O"}, {{"A", 50}, {"S", 50}}},
        {{"A", "A"}, {{"A", 75}, {"O", 25}}},
        {{"A", "S"}, {{"A", 25}, {"S", 25}, {"O", 25}, {"AS", 25}}},
        {{"A", "AS"}, {{"A", 50}, {"S", 25}, {"AS", 25}}},
        {{"S", "S"}, {{"S", 75}, {"O", 25}}},
        {{"AS", "S"}, {{"A", 25}, {"S", 50}, {"AS", 25}}},
        {{"AS", "AS"}, {{"A", 25}, {"S", 25}, {"AS", 50}}}
    };

    int n;
    cin >> n;
    while (n--) {
        string a, b, c;
        cin >> a >> b >> c;
        if (a > b) swap(a, b);
        if (mp[{a, b}][c] == 0) cout << "NO\n";
        else cout << mp[{a, b}][c] << '\n';
    }
}