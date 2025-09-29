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
    string a, b;
	while (getline(cin, a), getline(cin, b)) {
		map<char, int> mp, ans;
		for (auto c : a) mp[c]++;
		for (auto c : b) if (mp[c]-- > 0) ans[c]++;
		for (auto i : ans) while (i.se--) cout << i.fi;
		cout << '\n';
	}
}