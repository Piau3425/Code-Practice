#include <bits/stdc++.h>
using namespace std;
#define int long long

int ans, cnt;

void f(int x) {
	cnt++;
	if (x == 1) return void(ans = max(ans, cnt));
	if (x&1) return f(3*x+1);
	return f(x/2);
}

signed main() {
	int a, b;
	while (cin >> a >> b) { cout << a << ' ' << b << ' ';
		ans = -1e9;
		if (a > b) swap(a, b);
		for (int i = a; i <= b; i++) {
			cnt = 0;
			f(i);
		}
		cout << ans << endl;
	}
}