#include <bits/stdc++.h>
using namespace std;

#define N 1000000
#define int long long

signed main() {
	vector<int> v(N+1), ps(N); int k = 0, now = 0;
	for (int i = 0; i < N; i++) {
		if (!(i%2)) k++;
		now += k;
		v[i] = now;
	}
	int g = 0;
	for (int i = 1; i < N; i++) {
		ps[i] = g;
		g += v[i-1];
	}
	int n, last = 0;
	while (cin >> n, n >= 3) cout << ps[n-2] << '\n';
}