#include <bits/stdc++.h>
using namespace std;

#define int long long
#define N 2000000
#define all(x) (x).begin(), (x).end()

signed main() {
	vector<int> p(N+1, 1), ps; p[0] = p[1] = 0;
	for (int i = 2; i < N; i++) {
		if (p[i]) for (int j = i*i; j < N; j += i) p[j] = 0;
	}
	for (auto &i : p) if (i) ps.push_back(&i-p.data());
	
	int n;
	while (cin >> n, n) {
		if (find(all(ps), n) != ps.end()) {
			cout << "0\n";
			continue;
		}
		auto it = lower_bound(all(ps), n);
		if (it == ps.begin()) cout << *it << '\n';
		else cout << *it - *(prev(it)) << '\n';
	}
}