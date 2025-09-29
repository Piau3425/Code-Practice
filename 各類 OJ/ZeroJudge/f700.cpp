#include <iostream>
using namespace std;

int main(){
    string s;
    getline(cin, s);

    cout << s << '\n';
    for(int i = 0; i < s.length(); i++)
        cout << '~';
}