#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    for (auto &c : s) c = ((c-'a'+25)%26)+'a';
    cout << s << endl;
}