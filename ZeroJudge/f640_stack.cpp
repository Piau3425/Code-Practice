#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <string>
using namespace std;

int f(int a){
    return 2*a-3;
}

int g(int a, int b){
    return 2*a+b-7;
}

int h(int a, int b, int c){
    return 3*a-2*b+c;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string tmp;
    vector<string> s;
    stack<int> n;
    while(cin >> tmp)
        s.push_back(tmp);
    reverse(s.begin(), s.end());

    for(int i = 0; i < s.size(); i++){
        if(s[i] == "f"){
            int a = n.top(); n.pop();
            n.emplace(f(a));
        }
        else if(s[i] == "g"){
            int a = n.top(); n.pop();
            int b = n.top(); n.pop();
            n.emplace(g(a, b));
        }
        else if(s[i] == "h"){
            int a = n.top(); n.pop();
            int b = n.top(); n.pop();
            int c = n.top(); n.pop();
            n.emplace(h(a, b, c));
        }
        else
            n.push(stoi(s[i]));
    }

    cout << n.top();
}