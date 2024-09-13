#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	map<string, int> mp;
	for (cin >> n; n; n--) {
		string s;
		cin >> s;
		mp[s]++;
		cin >> s >> s;
	}
	for (auto i : mp) cout << i.first << ' ' << i.second << '\n';
}