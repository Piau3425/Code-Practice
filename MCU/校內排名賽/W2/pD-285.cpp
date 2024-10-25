#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
	string s;
	while (cin >> s) {
		int tx, ty;
		char tdir;
        vector<tuple<string, int, int, char>> words; 
		cin >> tx >> ty >> tdir;
		words.push_back(make_tuple(s, --tx, --ty, tdir));
		while (cin >> s && s != "#") {
			cin >> tx >> ty >> tdir;
			words.push_back(make_tuple(s, --tx, --ty, tdir));
		}

        //for (auto [s, x, y, d] : words) cout << s << ' ' << x << ' ' << y << ' ' << d << '\n';

		int n, m;
		cin >> n >> m;
		vector<vector<char>> v(m, vector<char>(n, ' '));
		
		for (auto [s, x, y, d] : words) {
			int dx = 0, dy = 0;
			if (d == 'r') dx = 1;
			if (d == 'l') dx = -1;
			if (d == 'u') dy = -1;
			if (d == 'd') dy = 1;
			for (auto c : s) {
				v[y][x] = c;
				x += dx; y += dy;
			}
		}

        for (auto i : v) {
            for (auto j : i) cout << j;
            cout << "!!\n";
        }

		string ans = "", sol;
		char c;
		
        for (auto i : v) for (auto j : i) if (j != ' ')  ans += j;

        /*
		for (auto i : v) {
            for (auto j : i) {
                if (j == ' ') {
                    if (ans.size() && ans[ans.size()-1] != ' ') ans += ' ';
                }
                else ans += j;
            }
		}*/
		//if (ans[ans.size()-1] == ' ') ans.erase(ans.size()-1); 
		ans += "$";
		
		cin.ignore();
		getline(cin, s);
        for (auto c : s) {
			if (c != ' ') sol += c;
		}
        
        /*
		for (auto c : s) {
			if (c == ' ') {
				if (sol.size() && sol[sol.size()-1] != ' ') sol += ' ';
			}
			else sol += c;
		}*/
		
		cout << ans << '\n' << sol << '\n';
		if (ans == sol) cout << "The solution is correct.\n";
		else cout << "The solution is incorrect.\n";
	}
}