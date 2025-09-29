/*
Presentation Error，尚未解決
*/

#include <iostream>
#include <stack>
#include <map>
#include <vector>
#include <iomanip>
using namespace std;

vector<pair<int, string>> unit = {
    {10000000, " kuti "},
    {100000, " lakh "},
    {1000, " hajar "},
    {100, " shata "},
    {1, " "}
};
stack<string> s;

void output(int input){
    //cout << setw(4);
    for(int i = 0; i < 5; i++){
        if(input/unit[i].first){
            cout << input/unit[i].first << unit[i].second;
            input %= unit[i].first;
        }
    }
}

int main(){
    long long input;
    int count = 1;
    while(cin >> input){
        cout << setw(4) << count++ << ". ";
        if(!input){
            cout << "0\n";
            continue;
        }
        int l = input/10000000, r = input%10000000;
        output(l);
        if(l > 0)
            cout << "kuti ";
        if(r)
            output(r);
        cout << '\n';
    }
}