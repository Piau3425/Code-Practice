#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<vector<string>> v(3);
    string tmp;
    int i = 0;
    while(cin >> tmp){
        v[i].push_back(tmp);
        i = (i+1)%3;
    }

    for(auto val : v[0])
        cout << val << ' ';
    cout << '\n';
    for(auto val : v[1])
        cout << val << ' ';
    cout << '\n';
    for(auto val : v[2])
        cout << val << ' ';
    cout << '\n';
}