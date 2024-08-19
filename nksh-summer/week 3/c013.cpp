#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) { // n 個測試資料
        int A, F;
        cin >> A >> F;
        for (int j = 0; j < F; j++) { // F 個波
            for (int k = 1; k <= A; k++) { //1 ~ A
                for (int g = 0; g < k; g++) {
                    cout << k;
                }
                cout << '\n';
            }

            for (int k = A-1; k > 0; k--) {
                for (int g = 0; g < k; g++) {
                    cout << k;
                }
                cout << '\n';
            }

            cout << '\n';
        }
    }
}
