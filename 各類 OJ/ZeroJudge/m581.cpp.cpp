#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define se second
#define INF LONG_LONG_MAX/1000
#define WA() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define int long long
#define PII pair<int, int>

signed main() { WA();
    int n; cin >> n;
    vector<int> v(n), a(n);
    for (auto &i : v) cin >> i;
    while (cin >> n, n) {
        n--;
        if (a[n]) return cout << "Wrong", 0;
        a[n] = 1;
    }
    for (int i = 0; i < v.size(); i++) if (!a[i] && v[i] == -1) return cout << "Werewolves", 0;
    cout << "Townsfolk";
}