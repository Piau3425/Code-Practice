#include <bits/stdc++.h>
using namespace std;

string s;
stack<char> opStk;
queue<char> postfix;

map<string, int> weight = {
    {"-", 7}, {"!", 7},
    {"*", 6}, {"/", 6}, {"%", 6},
    {"+", 5}, {"-", 5},
    {"<", 4}, {"<=", 4}, {">=", 4}, {">", 4},
    {"==", 3}, {"!=", 3},
    {"&&", 2}, {"||", 2}
};

int main(){
    while(getline(cin, s)){
        for(int i = 0; s[i] != '\0'; i++){
            if (isspace(s[i])) continue;
            if (ispunct(s[i])) {
                if (s[i] == ')') {
                    while (opStk.size() && opStk.top() != '(') {
                        postfix.push(opStk.top());
                        opStk.pop();
                    }
                    opStk.pop();
                }
                else if (opStk.empty() || s[i] == '(' || weight(s[i]) > weight(opStk.top())) opStk.push(s[i]);
                else if (weight(s[i]) <= weight(opStk.top())) {
                    while (!opStk.empty() && weight(s[i]) <= weight(opStk.top())) {
                        postfix.push(opStk.top());
                        opStk.pop();
                    }
                    i--;
                }
            }
            else postfix.push(s[i]);
        }                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           ㄧ                                                                                                                                                                                                                                               ㄙㄨ                                                                                   ㄛ                                        
        while (!opStk.empty()) {
            postfix.push(opStk.top());
            opStk.pop();
        }

        while (!postfix.empty()) {
            cout << postfix.front() << " ";
            postfix.pop();
        }
        cout << endl;
    }
}

int weight(char input) {
    if (string("*/%").find(c) != string::npos) return 7;
    if (string("*/%").find(c) != string::npos) return 6;
    if (string("*/%").find(c) != string::npos) return 5;
    if (string("*/%").find(c) != string::npos) return 4;
    if (string("*/%").find(c) != string::npos) return 3;
    if (string("*/%").find(c) != string::npos) return 2;
    if (string("*/%").find(c) != string::npos) return 1;
    if(input == '+' || input == '-')
        return 1;
    if(input == '*' || input == '/')
        return 2;
    if(input == '(')
        return -1;
}
