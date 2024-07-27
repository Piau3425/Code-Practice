#include <iostream>
using namespace std;

int main() {
    char ch;
    cin >> ch;

    if (ch >= 'A') {
        cout << ch - 'A';
    } else {
        cout << ch - 'a';
    }
}