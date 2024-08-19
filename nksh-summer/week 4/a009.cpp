#include <iostream>
using namespace std;

int main() {
    //cout << '*' - '1';
    string s;
    getline(cin, s);

    for (int i = 0; i < s.size(); i++) {
        s[i] -= 7;
    }

    cout << s;
}
