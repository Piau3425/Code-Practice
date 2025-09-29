#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> v1(n, vector<int>(m)); // v1[i][j] == server_i -> country_j : f
    for (auto &i : v1) for (auto &j : i) cin >> j;

    int mn = 1e9;
    while (k--) {
        vector<vector<int>> v2(m, vector<int>(m, 0)); // v2[i][j] country_i -> country_j : f
        vector<int> c(n); // c[sever] = country
        for (auto &i : c) cin >> i;

        // c[sever] = country
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) v2[c[i]][j] += v1[i][j];
        }

        int sum = 0;
        for (int i = 0; i < m; i++) for (int j = 0; j < m; j++) {
                if (i == j) sum += v2[i][j];
                else {
                    if (v2[i][j] <= 1000) sum += v2[i][j]*3;
                    else sum += 1000*3 + (v2[i][j]-1000)*2;
                }
        }
        
        mn = min(mn, sum);
    }

    cout << mn;
}