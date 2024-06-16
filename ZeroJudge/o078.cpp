#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
using namespace std;

vector<string> subs;
unordered_set<string> s;
string mom, son;
int len;

void dfs(string save){
    if(save.length() == len){
        subs.push_back(save);
        return;
    }

    for(int i = 0; i < mom.length(); i++)
        dfs(save + mom[i]);
}

int main(){
    cin >> mom >> len >> son;
    dfs("");

    for(int i = 0; i < son.length() - len + 1; i++)
        s.insert(son.substr(i, len));

    for(int i = 0; i < subs.size(); i++)
        if(s.count(subs[i]) == 0){
            cout << subs[i];
            break;
        }
}