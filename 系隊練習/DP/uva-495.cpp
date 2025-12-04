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

string sad(string a, string b) { // string add = sad
    reverse(all(a)); reverse(all(b));
    int k;
    for (int i = 0; i < b.size(); i++) {
        a[i] += b[i]-'0';
        while (a[i] > '9' && i+1 < a.size()) a[i] -= 10, a[i+1]++;
    }
    if (a.back() > '9') a.back() -= 10, a.pb('1');
    return string(a.rbegin(), a.rend());
}

signed main() { WA();
    vector<string> v(5001);
    v[0] = "0", v[1] = "1";
    for (int i = 2; i <= 5000; i++) v[i] = sad(v[i-1], v[i-2]);
    int n;
    while (cin >> n) cout << "The Fibonacci number for " << n << " is " << v[n] << '\n';
}