#include <iostream>
using namespace std;

int main() {
    char ch, a, b;
    cin >> a >> b;

    if (a <= b) {
        cout << b - a;
    } else {
        cout << 'Z' - a + b - 'A' + 1;
    }
}