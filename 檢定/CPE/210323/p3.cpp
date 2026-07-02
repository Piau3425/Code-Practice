#include <bits/stdc++.h>
using namespace std;

signed main() {
	for (int n, t = 0; cin >> n, n;) { if (t++) cout << '\n';
		bool flag = 1;
		
		for (int i = 12345; i <= 99999; i++) {
			if (i%n != 0) continue;
			string a = to_string(i), b = to_string(i/n);
			unordered_set<int> st;
			for (auto c : a) st.insert(c);
			if (st.size() < 5) continue;
			while (b.size() < 5) b = "0" + b;
			for (auto c : b) st.insert(c);
			if (st.size() != 10) continue;
			
			cout << a << " / " << b << " = " << n << '\n', flag = 0;
		}
		
		if (flag) cout << "There are no solutions for " << n << ".\n";
	}
}