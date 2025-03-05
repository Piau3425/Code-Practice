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
    string a, b;
    while (getline(cin, a) && getline(cin, b)) {
    	vector<vector<int>> v(sz(a)+1, vector<int>(sz(b)+1));
    	for (int i = 1; i <= sz(a); i++) {
    		for (int j = 1; j <= sz(b); j++) {
    			if (a[i-1] == b[j-1]) v[i][j] = v[i-1][j-1] + 1;
    			else v[i][j] = max(v[i-1][j], v[i][j-1]);
    		}
    	}
    	
    	cout << v[sz(a)][sz(b)] << '\n';
    }
}