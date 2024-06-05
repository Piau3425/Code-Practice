#include <iostream>
#include <map>
using namespace std;

int main(){ ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    while(cin >> n){
        map<string, int> mp;
        int i = 1;
        while(n--){
            string input;
            cin >> input;
            if(mp[input])
                cout << "Old! " << mp[input] << '\n';
            else{
                cout << "New! " << i << '\n';
                mp[input] = i;
                i++;
            }
        }
    }
}