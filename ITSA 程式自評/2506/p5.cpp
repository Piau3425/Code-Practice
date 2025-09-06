#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define se second
#define INF LONG_LONG_MAX/1000
#define WA() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define int long long
#define PII pair<int, int>

vector<string> v;
int n, m;

bool check(int i, int j) {
    return i < n && i >= 0 && j < m && j >= 0 && v[i][j] != '1';
}

bool check2(int i, int j) {
    return v[i][j] != 'b' && v[i][j] != 'B';
}

signed main() { WA();
    cin >> n;
    v.resize(n);
    for (auto &i : v) cin >> i;
    m = v[0].size();
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
        if (v[i][j] == 'b') {
            if (check(i+1, j) && check2(i+1, j)) v[i+1][j] = 'k';
            if (check(i-1, j) && check2(i-1, j)) v[i-1][j] = 'k';
            if (check(i, j+1) && check2(i, j+1)) v[i][j+1] = 'k';
            if (check(i, j-1) && check2(i, j-1)) v[i][j-1] = 'k';
        }
        if (v[i][j] == 'B') {
            int ii = i+1, jj = j;
            while (check(ii, jj)) {
                if (check2(ii, jj)) v[ii][jj] = 'k';
                ii++;
            }
            ii = i-1, jj = j;
            while (check(ii, jj)) {
                if (check2(ii, jj)) v[ii][jj] = 'k';
                ii--;
            }
            ii = i, jj = j+1;
            while (check(ii, jj)) {
                if (check2(ii, jj)) v[ii][jj] = 'k';
                jj++;
            }
            ii = i, jj = j-1;
            while (check(ii, jj)) {
                if (check2(ii, jj))v[ii][jj] = 'k';
                jj--;
            }
        }
    }
    /*
    for (auto &i : v) {
        for (auto &j : i) cout << j;
        cout << '\n';
    }
    */
    int cnt = 0;
    for (auto &i : v) for (auto &j : i) if (j == '0') cnt++;
    cout << cnt << '\n';
}