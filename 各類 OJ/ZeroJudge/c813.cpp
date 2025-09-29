#include <bits/stdc++.h>
using namespace std;

int g(long long x) {
	int sum = 0;
	while (x) {
		sum += x % 10;
		x /= 10;
	}
	if (sum/10) return g(sum);
	return sum;
}

int main() {
	long long n;
	while (cin >> n && n) cout << g(n) << '\n'; 
}