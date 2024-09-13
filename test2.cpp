#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	for (cin >> n; n; n--) {
		int s, d;
        bool f = true;
		cin >> s >> d;
		for (int i = 0; i <= s; i++) { // i, s-i
			if (s-i-i == d) {
                cout << s-i << ' ' << i << '\n';
                f = false;
            }
		}
        if (f) cout << "impossible\n";
	}
}