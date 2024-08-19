#include <iostream>
#include <vector>
using namespace std;

#define int long long

signed main() { ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m, tmp;
	cin >> n >> m;
	vector<int> x(n), y(n), count(n, 0), win, lose, idx(n);
	for (auto &i : x) cin >> i;
	for (auto &i : y) cin >> i;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		idx[i] = tmp - 1;
	}
	
	while (idx.size() > 1) {
		win.clear(); lose.clear();
		for (int i = 0; i+1 < idx.size(); i += 2) {
			int l = idx[i], r = idx[i+1];
			int a = x[l], b = y[l], c = x[r], d = y[r];
			if (a*b >= c*d) {
				x[l] += c*d/(2*b);
				y[l] += c*d/(2*a);
				win.push_back(l);
				count[r]++;
				if(count[r] < m){
					x[r] += c/2;
					y[r] += d/2;
					lose.push_back(r);
				}
			}
			else {
				x[r] += a*b/(2*d);
				y[r] += a*b/(2*c);
				win.push_back(r);
				count[l]++;
				if (count[l] < m) {
					x[l] += a/2;
					y[l] += b/2;
					lose.push_back(l);
				}
			}
		}

		if (idx.size() & 1) win.push_back(idx[idx.size()-1]);
			
		idx.clear();
        for(auto val : win) idx.push_back(val);
        for(auto val : lose) idx.push_back(val);
    }

	cout << idx[0] + 1;
}