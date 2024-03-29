#include <iostream>
#include <vector>
using namespace std;

vector<int> loc;

int main(){
    string s;
    cin >> s;
    char target;
    cin >> target;

    for(int i = 0; i < s.length(); i++){
        if(isupper(s[i]))
            s[i] += ' ';
    }
    if(isupper(target))
        target += ' ';

    for(int i = 0; i < s.length(); i++){
        if(s[i] == target)
            loc.push_back(i);
    }

    for(int i = 0; i < loc.size()-1; i++){
        cout << loc[i+1] - loc[i] << " ";
    }
}
