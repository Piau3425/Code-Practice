#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    while (scanf("%d", &n), n) {
        vector<vector<int>> v(n, vector<int>(n));
        for (auto &i : v) for (auto &j : i) scanf("%d", &j);
        int x, y, r, c; r = c = 0;
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = 0; j < n; j++) cnt += v[i][j];
            if (cnt&1) r++, x = i+1;
        }
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = 0; j < n; j++) cnt += v[j][i];
            if (cnt&1) c++, y = i+1;
        }
        if (r == 1 && c == 1) printf("Change bit (%d,%d)\n", x, y);
        else if (!r && !c) printf("OK\n");
        else printf("Corrupt\n");
    }
}