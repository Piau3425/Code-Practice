#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


string gcd(string s1,string s2){
    if(s1 + s2 == s2 + s1){
        return s1.substr(0, __gcd(s1.size(), s2.size()));
    }
    else
        return "= =";
}

int main(){
    string s1, s2;
    while(cin >> s1){
        cin >> s2;
        cout << gcd(s1, s2) << endl;
    }
}