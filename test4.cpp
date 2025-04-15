#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define WA() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long
#define PII pair<int, int>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()

int n, mx = -1e9, ans = 1;
vector<int> bit;
vector<PII> v;

void update(int x) {
    for (; x <= mx; x += x&-x) bit[x] += 1;
}

int query(int x) {
    int sum = 0;
    for (; x; x -= x&-x) sum += bit[x];
    return sum;
}

signed main() { WA();
    cin >> n;	

	v.assign(n, PII(0, 0));
	for (auto &i : v) cin >> i.fi >> i.se;
	map<int, int> mp;
	for (auto &i : v) mp[i.se]++;
	for (auto &i : mp) i.se = ans++;
	for (auto &i : v) i.se = mp[i.se], mx = max(mx, i.se);
	bit.assign(mx+1, 0);
	sort(all(v));

/* 	for (auto i : v) cout << i.fi << ' ' << i.se << '\n';
	cout << "========\n"; */

	ans = 0;
	for (int i = 0; i < n; i++) {
		ans += query(v[i].se);
		update(v[i].se);
	}

	map<PII, int> freq;
	for (auto i : v) freq[i]++;
	for (auto i : freq) ans += (i.se*(i.se-1))>>1;

	cout << ans << '\n';
}