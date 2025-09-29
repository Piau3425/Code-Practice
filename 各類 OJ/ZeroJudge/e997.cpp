#include <iostream>
#include <stack>
using namespace std;

stack<string> stk;
string name;

int main(){
    while(1){
        cin >> name;
        if(isdigit(name[0])){
            int num = stoi(name);
            for(int i = 0; i < num-1; i++)
                stk.pop();
            break;
        }
        else
            stk.push(name);
    }

    cout << stk.top();
}
