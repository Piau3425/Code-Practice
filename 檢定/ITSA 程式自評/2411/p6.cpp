#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define se second
#define INF 0x3f3f3f3f
#define WA() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define int long long

signed main() { WA();
    int n, m;
    cin >> n >> m;
    vector<vector<char>> v(n, vector<char>(m));
    for (auto &i : v) for (auto &j : i) cin >> j;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
        if (isdigit(v[i][j])) {
            int mx = v[i][j] - '0', sum = 0, unk = 0;
            for (int ny = i-1; ny <= i+1; ny++) for (int nx = j-1; nx <= j+1; nx++) {
                if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
                sum += (v[ny][nx] == '*');
                unk += (v[ny][nx] == '?');
            }
            if (!(mx >= sum && mx <= sum + unk)) {
                cout << "ERROR\n";
                exit(0);
            }
        }
    }

    cout << "PASS\n";
}