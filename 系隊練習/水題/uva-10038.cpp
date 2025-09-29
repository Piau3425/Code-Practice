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
    int n;
    while (cin >> n) {
    	vector<int> v(n), d(n-1);
    	for (auto &i : v) cin >> i;
    	for (int i = 0; i < n-1; i++) d[i] = abs(v[i+1] - v[i]);
    	sort(all(d));
    	int ck = 0;
    	for (int i = 0; i+1 < d.size(); i++) if (abs(d[i]-d[i+1]) != 1) ck = 1;
    	if (n == 1) cout << "Jolly\n";
    	else if (ck || d[0] != 1) cout << "Not jolly\n";
    	else cout << "Jolly\n";
    }
}