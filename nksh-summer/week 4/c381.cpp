#include <iostream>
using namespace std;

int main(){
    string str, tmp;
    int n, m, idx;
    while (cin >> n >> m && n != 0 && m != 0) {
        str = "";

        for (int i = 0; i < n; i++) {
            cin >> tmp;
            str += tmp;
        }

        for (int i = 0; i < m; i++) {
            cin >> idx;
            cout << str[idx-1];
        }
        cout << '\n';
    }
}
