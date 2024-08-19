#include <iostream>
using namespace std;

int main() {
    int save[26] = {};
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++) save[s[i]-'a']++;
    for (int i = 0; i < 26; i++) cout << char(i+'a') << ": " << save[i] << '\n';
}