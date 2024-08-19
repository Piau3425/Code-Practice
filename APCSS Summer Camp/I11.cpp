#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
using namespace std;

unordered_set<string> s;
string mom, son, ans = "";
int len;

void dfs(string save){
    if(save.length() == len){
        if(s.count(save) == 0 && ans == "")
            ans = save;
        return;
    }

    for(int i = 0; i < mom.length(); i++)
        dfs(save + mom[i]);
}

int main(){
    cin >> mom >> len >> son;

    for(int i = 0; i < son.length() - len + 1; i++)
        s.insert(son.substr(i, len));

    dfs("");
    cout << ans;
}