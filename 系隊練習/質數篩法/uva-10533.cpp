#include <bits/stdc++.h>
using namespace std;
#define int long long
#define WA() ios::sync_with_stdio(0);cin.tie(0)
#define MAX 1000000

vector<int> p(MAX, 1), dp;

bool check(int sum) {
	string s = to_string(sum);
	sum = 0;
	for (auto c : s) sum += c-'0';
	return p[sum];
}

signed main() { WA();
	int n, a, b;
	p[0] = 0, p[1] = 0;
	for (int i = 2; i < MAX; i++) if (p[i]) for (int j = i*i; j < MAX; j += i) p[j] = 0;
	for (int i = 2; i < MAX; i++) if (p[i] && check(i)) dp.push_back(i); 
	scanf("%lld", &n);
	while (n--) {
		scanf("%lld %lld", &a, &b);
		printf("%d\n", upper_bound(dp.begin(), dp.end(), b) - lower_bound(dp.begin(), dp.end(), a));
	}
}