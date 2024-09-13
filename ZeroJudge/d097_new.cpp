#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	while (cin >> n) {
		vector<int> a(n), b(n-1);
		int f = 0;
		for (auto &i : a) cin >> i;
		
		if (n == 1) {
			cout << "Jolly\n";
			continue;
		}
		
		for (int i = 0; i+1 < n; i++) b[i] = abs(a[i]-a[i+1]);
		sort(b.begin(), b.end());
		for (int i = 0; i+1 < n-1; i++) f += b[i]+1 == b[i+1];
		
		if (f == n-2 && b[0]) cout << "Jolly\n";
		else cout << "Not jolly\n";
	}	
}