#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;

    for (int i = 0; i < 6; i++) {
        if (s[i] - s[i+1] < 0) {
            cout << (s[i] - s[i+1]) * -1;
        } else {
            cout << (s[i] - s[i+1]);
        }
    }
}
