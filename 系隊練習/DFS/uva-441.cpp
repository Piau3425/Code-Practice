#include <bits/stdc++.h>
using namespace std;
#define int long long

int n;
vector<int> save, v;

void rec(int idx) {
	if (save.size() == 6) {
		for (int i = 0; i < 6; i++) cout << save[i] << " \n"[i+1 == 6];
		return;
	}
	if (idx == n) return;
	
	save.push_back(v[idx]);
	rec(idx+1);
	save.pop_back();
	rec(idx+1);
}

signed main() {
	int i = 0;
	while (cin >> n && n) {
		if (i++) cout << '\n';
		v.resize(n);
		for (auto &i : v) cin >> i;
		rec(0);
		v.clear();
	}
}