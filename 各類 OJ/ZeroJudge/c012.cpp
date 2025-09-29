#include <bits/stdc++.h>
using namespace std;

bool cmp (pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second) return a.first > b.first;
	return a.second < b.second;
}

int main() {
	string s;
	bool f = false;
	while (getline(cin, s)) {
		if (f) cout << '\n';
		vector<pair<int, int>> v(129); // char, freq
		for (int i = 1; i <= 128; i++) v[i] = {i, 0};
		for (auto c : s) v[c].second++;
		sort(v.begin(), v.end(), cmp);
		for (auto i : v) if (i.second) cout << i.first << ' ' << i.second << '\n';
		f = true;
	}
}