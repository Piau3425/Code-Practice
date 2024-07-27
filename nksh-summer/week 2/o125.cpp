#include <iostream>
using namespace std;

int main() {
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);

    if (s1 > s2) {
        cout << "True";
    } else {
        cout << "False";
    }
}