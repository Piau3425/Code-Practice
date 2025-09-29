#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	while (cin >> n) {
		vector<int> v(n);
		map<int, int> mp;
		for (auto &i : v) {
			cin >> i;
			mp[i]++;
		}
		sort(v.begin(), v.end());
		
		if (n&1) cout << v[n/2] << ' ' << mp[v[n/2]] << ' ' << "1\n";
		else cout << v[n/2-1] << ' ' << (v[n/2] == v[n/2-1] ? mp[v[n/2]] : mp[v[n/2-1]] + mp[v[n/2]]) << ' ' << v[n/2]-v[n/2-1]+1 << '\n';
	}
}