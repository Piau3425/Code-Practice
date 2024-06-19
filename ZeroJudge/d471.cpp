#include <iostream>
#include <vector>
using namespace std;

vector<string> ans;
string bit = "01";
int len;

void dfs(string save){
    if(save.length() == len){
        ans.push_back(save);
        return;
    }    

    for(int i = 0; i < 2; i++)
        dfs(save + bit[i]);
}

int main(){
    while(cin >> len){
        ans.clear();
        dfs("");
        for(auto str : ans)
            cout << str << '\n';
    }
}