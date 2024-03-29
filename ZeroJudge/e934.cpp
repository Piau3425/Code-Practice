#include <iostream>
#include <map>
using namespace std;

string s, a;

map<char, char> mp = {
    {'T', 'A'},
    {'A', 'U'},
    {'G', 'C'},
    {'C', 'G'}
};

int main(){
    getline(cin, s);

    for(int i = 0; s[i] != '\0'; i++)
        a += mp[s[i]];

    cout << a;
}
