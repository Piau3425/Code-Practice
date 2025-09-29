#include <iostream>
#include <stack>
using namespace std;

stack<char> stk;

int main(){
    string s;
    getline(cin, s);

    int sum = 0;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == '(')
            stk.push(s[i]);
        if(s[i] == ')'){
            if(!stk.empty()){
                stk.pop();
                sum++;
            }
            else{
                cout << "0";
                return 0;
            }
        }
    }

    if(stk.empty())
        cout << sum;
    else
        cout << "0";
}
