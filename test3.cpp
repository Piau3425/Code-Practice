#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
#include <stack>
#include <algorithm>
using namespace std;

int main() {
    int n, m, k;
    cin >> n;
    int dx[]{1, 0, -1, 0, 0}, dy[]{0, 1, 0, -1, 0}; // 路徑（含不動）

    while (cin >> m >> k) {
        vector<vector<int>> visitR(m, vector<int>(m, 0));   // 造訪R
        vector<vector<int>> visitB(m, vector<int>(m, 0));   // 造訪B
        vector<vector<int>> visitY(m, vector<int>(m, 0));   // 造訪Y
        vector<vector<string>> on(m, vector<string>(m, "")); // 先不合成色
        queue<tuple<int, int, string>> q; // 紀錄點

        char a;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a;
                if (a == 'R') {
                    q.push(make_tuple(i, j, "R"));
                    visitR[i][j] = 1;
                    on[i][j] = "R";
                } else if (a == 'Y') {
                    q.push(make_tuple(i, j, "Y"));
                    visitY[i][j] = 1;
                    on[i][j] = "Y";
                } else if (a == 'B') {
                    q.push(make_tuple(i, j, "B"));
                    visitB[i][j] = 1;
                    on[i][j] = "B";
                }
            }
        }
        
        for (int step = 0; step < k; step++) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto [x, y, s] = q.front();
                q.pop();
                for (int j = 0; j < 5; j++) {
                    int nx = x + dx[j];
                    int ny = y + dy[j];
                    if (nx >= 0 && nx < m && ny >= 0 && ny < m) {
                        if (s.find('R') != string::npos && !visitR[nx][ny]) {
                            on[nx][ny] += 'R';
                            visitR[nx][ny] = 1;
                            q.push(make_tuple(nx, ny, on[nx][ny]));
                        }
                        if (s.find('B') != string::npos && !visitB[nx][ny]) {
                            on[nx][ny] += 'B';
                            visitB[nx][ny] = 1;
                            q.push(make_tuple(nx, ny, on[nx][ny]));
                        }
                        if (s.find('Y') != string::npos && !visitY[nx][ny]) {
                            on[nx][ny] += 'Y';
                            visitY[nx][ny] = 1;
                            q.push(make_tuple(nx, ny, on[nx][ny]));
                        }
                    }
                }
            }
        }
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                sort(on[i][j].begin(), on[i][j].end());
                if (on[i][j] == "B") on[i][j] = "B";
                else if (on[i][j] == "R") on[i][j] = "R";
                else if (on[i][j] == "Y") on[i][j] = "Y";
                else if (on[i][j] == "BR" || on[i][j] == "RB") on[i][j] = "P"; // Purple
                else if (on[i][j] == "RY" || on[i][j] == "YR") on[i][j] = "O"; // Orange
                else if (on[i][j] == "BY" || on[i][j] == "YB") on[i][j] = "G"; // Green
                else if (on[i][j] == "BRY" || on[i][j] == "BYR" || on[i][j] == "RBY" ||
                         on[i][j] == "RYB" || on[i][j] == "YBR" || on[i][j] == "YRB") on[i][j] = "D"; // Dark
                else on[i][j] ="W";
                cout << on[i][j];
                if (j < m - 1) cout << " ";
            }
            cout << '\n';
        }
    }
}