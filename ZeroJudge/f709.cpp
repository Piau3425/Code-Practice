#include <bits/stdc++.h>
using namespace std;

int main() {
	string days[] = {"Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};
	int m2d[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int m, d, n;
	for (cin >> n; n; n--) {
		cin >> m >> d;
		for (int i = 1; i < m; i++) d += m2d[i];
		cout << days[(d-1)%7] << '\n';
	}
}