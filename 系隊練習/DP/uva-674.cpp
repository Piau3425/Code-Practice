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
    int n;
    vector<int> v(7500, 1);
    for (int i = 5; i < 7500; i++) v[i] += v[i-5];
    for (int i = 10; i < 7500; i++) v[i] += v[i-10];
    for (int i = 25; i < 7500; i++) v[i] += v[i-25];
    for (int i = 50; i < 7500; i++) v[i] += v[i-50];
    while (cin >> n) cout << v[n] << '\n';
}