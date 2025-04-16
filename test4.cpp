#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define WA() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long
#define PII pair<int, int>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()

signed main() { WA();
    unordered_set<int> st; 
	for (int i = 0; i < 1000000; i++) {
		if (st.load_factor() >= 1) cout << st.bucket_count() << ' ' << st.bucket_size(0) << ' ' << st.load_factor() << '\n';
		st.insert(i);
	}
	deque<int> dq;
	stack<int> sta;
	sta.
}