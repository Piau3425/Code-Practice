#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n;
    while(cin >> n && n != 0){
        string input;
        cin >> input;
        int slice = input.length()/n;
        for(int i = 0; i+slice <= input.length(); i+=slice){
            reverse(input.begin()+i, input.begin()+i+slice);
        }
        cout << input << endl;
    }
}