#include <iostream>
using namespace std;

main() {
	int t; cin >> t; cin.ignore(); cin.ignore();
	while (t--) {
		string a, b, s;
		getline(cin, a); getline(cin, b);
		cout << b << '\n' << a << '\n';
		while (getline(cin, s), s != "") {
			for (auto &c : s) if (a.find(c) != string::npos) cout << b[a.find(c)]; else cout << c;
			cout << endl;
		}
		if (t) cout << endl;
	}
}