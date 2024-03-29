#include <iostream>
#include <string>
#include <map>

using namespace std;

string key;
int loop;

map<string, char> mp = {
    {"0 1 0 1", 'A'},
    {"0 1 1 1", 'B'},
    {"0 0 1 0", 'C'},
    {"1 1 0 1", 'D'},
    {"1 0 0 0", 'E'},
    {"1 1 0 0", 'F'}
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    while(cin >> loop && !cin.eof()){
        cin.ignore();
        for(int i = 0; i < loop; i++){
            getline(cin, key);
            cout << mp[key];
        }
        cout << endl;
    }
}
