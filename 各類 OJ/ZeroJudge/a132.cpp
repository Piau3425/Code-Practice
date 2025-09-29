#include <bits/stdc++.h>
using namespace std;

string s;
int cnt;

void br(int x) {
	if (!x) return;
	if (x%2) cnt++;
	s += x%2+'0';
	br(x/2);
}

int main() {
	int n;
	while (cin >> n && n) {
		s = ""; cnt = 0;
		br(n); reverse(s.begin(), s.end());
		cout << "The parity of " << s << " is " << cnt << " (mod 2).\n";
	}
}