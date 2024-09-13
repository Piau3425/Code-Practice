#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, i;
	for (cin >> n, i = 1; i <= n; i++) {
		string a, b;
		int na = 0, nb = 0;
		cin >> a >> b;
		for (auto c : a) na = (na+(c-'0'))*2;
		for (auto c : b) nb = (nb+(c-'0'))*2;
		na /= 2; nb /= 2;
		
		cout << "Pair #" << i << ": ";
		if (__gcd(na, nb) == 1) cout << "Love is not all you need!\n";
		else cout << "All you need is love!\n";
	}
}