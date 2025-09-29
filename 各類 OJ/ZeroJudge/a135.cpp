#include <iostream>
#include <map>
using namespace std;

map<string, string> mp = {
    {"HELLO", "ENGLISH"},
    {"HOLA", "SPANISH"},
    {"HALLO", "GERMAN"},
    {"BONJOUR", "FRENCH"},
    {"CIAO", "ITALIAN"},
    {"ZDRAVSTVUJTE", "RUSSIAN"}
};

int main(){
    int i = 1;
    string input;
    while(cin >> input && input != "#"){
        cout << "Case " << i << ": " << (mp.find(input) == mp.end() ? "UNKNOWN" : mp[input]) << '\n';
        i++;
    }
}