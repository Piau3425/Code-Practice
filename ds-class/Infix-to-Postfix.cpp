#include <iostream>
#include <cstdlib>
#include <stack>
#include <queue>

using namespace std;

string s;
stack<char> opStk;
queue<char> postfix;

int weight(char input);

int main(){
    while(getline(cin, s)){
        for(int i = 0; s[i] != '\0'; i++){
                if(isspace(s[i])) continue;
                if(ispunct(s[i])){
                    if(s[i] == ')'){
                        while(opStk.top() != '('){
                            postfix.push(opStk.top());
                            opStk.pop();
                        }
                        opStk.pop();
                    }
                    else if(opStk.empty() || s[i] == '(' || weight(s[i]) > weight(opStk.top()))
                        opStk.push(s[i]);
                    else if(weight(s[i]) <= weight(opStk.top())){
                        while(!opStk.empty() && weight(s[i]) <= weight(opStk.top())){
                            postfix.push(opStk.top());
                            opStk.pop();
                        }
                        i--;
                    }
                    /*else{
                        postfix.push(opStk.top());
                        opStk.pop();
                        opStk.push(s[i]);
                    }*/
                }
                else postfix.push(s[i]);
            }
            while(!opStk.empty()){
                postfix.push(opStk.top());
                opStk.pop();
            }

            while(!postfix.empty()){
                cout << postfix.front() << " ";
                postfix.pop();
            }
            cout << endl;
    }
}

int weight(char input){
    if(input == '+' || input == '-')
        return 1;
    if(input == '*' || input == '/')
        return 2;
    if(input == '(')
        return -1;
}
