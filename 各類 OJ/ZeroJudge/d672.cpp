#include <bits/stdc++.h>
using namespace std;

int n;

bool rec(string s) {
	n++;
	int sum = 0;
	for (auto c : s) sum += c-'0';
	if (sum > 10) return rec(to_string(sum));
	return sum == 9;
}

int main() {
	string s;
	while (cin >> s && s != "0") {
		n = 0;
		if (rec(s)) cout << s << " is a multiple of 9 and has 9-degree " << n << ".\n";
		else cout << s << " is not a multiple of 9.\n";
	}
}