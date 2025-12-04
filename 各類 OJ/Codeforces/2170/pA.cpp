#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define se second
#define INF LONG_LONG_MAX/1000
#define WA() cin.tie(0)->sync_with_stdio(0)
#define all(x) (x).begin(), (x).end()
#define int long long
#define PII pair<int, int>

int mx[] = {0, 1, 0, -1}, my[] = {1, 0, -1, 0};

signed main() { WA();
    int t; for (cin >> t; t--;) {
        int n; cin >> n;
        vector<vector<int>> v(n, vector<int>(n));
        int k = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                v[i][j] = k++;
            }
        }
        int mxx = -INF;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int sum = v[i][j];
                for (int k = 0; k < 4; k++) {
                    int nx = i+mx[k], ny = j+my[k];
                    if (nx < n && nx >= 0 && ny < n && ny >= 0) {
                        sum += v[nx][ny];
                    }
                }
                mxx = max(mxx, sum);
            }
        }
        cout << mxx << '\n';
    }
}