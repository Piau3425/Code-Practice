#include <iostream>
#include <sstream>
using namespace std;

int main(){
    stringstream ss;
    string s, tmp;
    getline(cin, s);
    ss.str(s);
    getline(cin, s);

    bool f = true;
    while(ss >> tmp){
        if(f) {
            cout << tmp;
            f = false;
        }
        else cout << ' ' << s << ' ' << tmp;
    }
}