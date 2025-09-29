#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main(){
    stringstream ss;
    string input;
    while(getline(cin, input)){
        double num, sum = 0;
        ss.str(input);
        ss.clear();
        string split;
        while(ss >> split){
            num = stod(split.substr(split.find(":")+1));
            if(stoi(split.substr(0, split.find(":"))) & 1)
                sum += num;
            else
                sum -= num;
        }
        cout << sum << '\n';
    }
}