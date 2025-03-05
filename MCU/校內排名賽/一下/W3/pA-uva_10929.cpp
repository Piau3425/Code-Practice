#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define se second
#define INF LONG_LONG_MAX/1000
#define WA() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define int long long
#define PII pair<int, int>

signed main() { WA();
    string s;
    while (cin >> s, s != "0") {
    	int sum = 0;
    	for (auto c : s) sum = (sum+c-'0')%11*10;
    	if (sum) cout << s << " is not a multiple of 11.\n";
    	else cout << s << " is a multiple of 11.\n";
    }
}