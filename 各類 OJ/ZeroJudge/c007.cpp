#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	bool f = true;
	while (getline(cin, s)) {	
		for (auto c : s)
			if (c == '\"') {
				cout << (f ? "``" : "''");
				f = !f;
			}
			else cout << c;
		cout << '\n';
	}
}