#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define se second
#define INF 0x3f3f3f3f
#define WA() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define int long long

signed main() { WA();
    int n, sum = 0;
    cin >> n;
    vector<int> v(n);
    for (auto &i : v) cin >> i;
    for (int i = 1; i < v.size(); i++) {
        if (v[i-1] > v[i]) {
            sum += v[i-1] - v[i];
            v[i] = v[i-1];
        }
    }
    cout << sum;
}