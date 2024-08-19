#include <iostream>
using namespace std;

int main() {
    int row, col, arr[100][100];

    while (cin >> row >> col) {
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                cin >> arr[i][j];
            }
        }

        for (int i = 0; i < col; i++) {
            for (int j = 0; j < row; j++) {
                cout << arr[j][i] << ' ';
            }

            cout << '\n';
        }
    }
}





int a = 10, b = 20, c, d;
int e;

e = min({a, b, c ,d});








