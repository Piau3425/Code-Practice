#include <bits/stdc++.h>
using namespace std;

int main() {
	string a, b;
	while (getline(cin, a), getline(cin, b)) {
		map<char, int> mp, ans;
		for (auto c : a) mp[c]++;
		for (auto c : b) if (isalpha(c) && mp[c]-- > 0) ans[c]++;
		for (auto i : ans) while (i.second--) cout << i.first;
		cout << '\n';
	}
}