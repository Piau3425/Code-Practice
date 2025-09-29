#include <bits/stdc++.h>
using namespace std;

int n, m;

bool cmp(int a, int b){
	if (a%m != b%m) return a%m < b%m;
	if (a&1 && b&1) return a > b;
	if (!(a&1) && !(b&1)) return a < b;
	return a&1;
}

int main(){
	while (cin >> n >> m, cout << n << ' ' << m << '\n', n && m){
		vector<int> v(n);
		for (auto &i : v) cin >> i;
		sort(v.begin(), v.end(), cmp);
		for (auto &i : v) cout << i << '\n';
	}
}