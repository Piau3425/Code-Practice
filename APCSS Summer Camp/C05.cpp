#include <bits/stdc++.h>
using namespace std;

int r, c;

bool check(int a, int b) {
    return (a >= 0 && a < r && b >= 0 && b < c);
}

int main() {
    int dx[] = {-1, 0, 1, -1, 1, -1, 0, 1};
    int dy[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    cin >> r >> c;
    vector<vector<int>> v(r, vector<int>(c));
    for (auto &a : v)
        for (auto &b : a)
            cin >> b;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            int sum = 0;
            for (int k = 0; k < 8; k++) if(check(i+dx[k], j+dy[k])) sum += v[i+dx[k]][j+dy[k]];
            cout << sum << " \n"[j+1 == c];
        }
    }

}