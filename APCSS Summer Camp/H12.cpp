#include <bits/stdc++.h>
using namespace std;

int main() {
    int r, c;
    cin >> r >> c;
    vector<vector<int>> v(r, vector<int>(c));
    for (auto &a : v) for (auto &b : a) cin >> b;
    vector<pair<int, int>> ans;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            int sum = 0;
            for (int k = 0; k < r; k++)
                for (int l = 0; l < c; l++)
                    if ((abs(i-k)+abs(j-l)) <= v[i][j]) sum += v[k][l];

            if (sum%10 == v[i][j]) ans.emplace_back(i, j);
        }
    }

    cout << ans.size() << '\n';
    for (auto i : ans) cout << i.first << ' ' << i.second << '\n';
}