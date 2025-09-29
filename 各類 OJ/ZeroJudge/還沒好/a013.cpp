#include <iostream>
#include <map>
using namespace std;

map<char, int> lti = {
    {'M', 1000},
    {'D', 500},
    {'C', 100},
    {'L', 50},
    {'X', 10},
    {'V', 5},
    {'I', 1}
};

map<int, char> itl = {
    {1000, 'M'},
    {500, 'D'},
    {100, 'C'},
    {50, 'L'},
    {10, 'X'},
    {5, 'V'},
    {1, 'I'}
};

int flti(string input){
    int sum = 0;
    for(int i = 0; i < input.length(); i++){
        
    }
    return sum;
}

string fitl(int input){
    string output = "";
    for(auto i = itl.rbegin(); i != itl.rend(); i++){
        for(int j = 0; j < input/i->first; j++){
            output += i->second;
        }
        input %= i->first;
    }

    return output;
}

int main(){
    string a, b;
    while(cin >> a >> b && a != "#"){
        int tmp = flti(a) - flti(b);
        cout << tmp;
        if(tmp == 0)
            cout << "ZERO\n";
        else
            cout << fitl(tmp) << "\n";
    }
}