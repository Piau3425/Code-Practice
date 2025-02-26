#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
	int n;
	while (cin >> n, n) {
		int mx = -1e9;
		map<string, int> mp;
		unordered_multiset<string> st;
		vector<int> v(5);
		while (n--) {
			string s;
			for (auto &i : v) cin >> i;
			sort(v.begin(), v.end());
			for (auto &i : v) s += to_string(i);
			mp[s]++;
			st.insert(s);
			mx = max(mx, mp[s]);
		}
		
		int sum = 0;
		for (auto i : st) sum += mp[i] == mx; 
		cout << sum << '\n';
	}
}