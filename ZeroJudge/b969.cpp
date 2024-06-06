#include <iostream>
#include <sstream>
using namespace std;

int main(){
    string input, name;
    stringstream ss;
    getline(cin, input);
    ss.str(input);
    getline(cin, input);
    while(ss >> name)
        cout << input << ", " << name << '\n';
}