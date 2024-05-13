#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n;
    string pw = "";
    while(cin >> n && !cin.eof()){
        for(int i = 1; i <= n; i++)
            pw += to_string(i);
        string o = string(pw.rbegin(), pw.rend());
        
    }
}
