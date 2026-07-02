#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define pb push_back
#define fi first
#define se second
#define INF LONG_LONG_MAX/1000
#define WA() cin.tie(0)->sync_with_stdio(0)
#define all(x) (x).begin(), (x).end()
#define int long long
#define PII pair<int, int>

template<typename T>
using rbtree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

signed main() { WA();
    int dx[] = {1, 2, 2, 1, -1, -2, -2, -1}, dy[] = {-2, -1, 1, 2, 2, 1, -1, -2};
    for (string a, b; cin >> a >> b;) {
    	vector<vector<int>> vis(8, vector<int>(8));
    	
        int ans = 0;
    	queue<tuple<int, int, int>> q; q.push({a[0]-'a', a[1]-1-'0', 0});
    	while (q.size()) {
    		auto [y, x, step] = q.front(); q.pop();

    		if (y == b[0]-'a' && x == b[1]-1-'0') {
    			ans = step;
    			break;
    		}
    		
    		for (int i = 0; i < 8; i++) {
				int nx = x + dx[i], ny = y + dy[i];
				if (nx >= 0 && nx < 8 && ny >= 0 && ny < 8 && !vis[ny][nx]) vis[ny][nx] = 1, q.push({ny, nx, step+1});
    		}
    	}

    	cout << "To get from " << a << " to " << b << " takes " << ans << " knight moves.\n";
    }
}