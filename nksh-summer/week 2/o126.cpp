#include <iostream>
using namespace std;

int main() {
    char a, b;
    cin >> a >> b;
    cout << (b - a + 26) % 26;
}
