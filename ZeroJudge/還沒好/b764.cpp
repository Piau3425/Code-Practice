#include <iostream>
#include <map>
using namespace std;

void solve(){
    map<string, int> m = {
        
    };
    string input, subs = "";
    int index = 0, sum = 0;
    cin >> input;
    while(sum >= 9){
        subs += input[index];
        sum = m[subs];
        index++;
    }
}

int main(){
    int t;
    while(t--){
        solve();
    }
}