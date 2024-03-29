#include <iostream>
#include <cstdlib>
#include <stack>
#include <cstring>
using namespace std;

stack<int> nStk;
string s;
int a, b;

int main(){
    while(cin >> s){
        for(int i = 0; s[i] != '\0'; i++){
            if(isdigit(s[i])){
                nStk.push(s[i]-'0');
            }
            if(ispunct(s[i])){
                b = nStk.top();
                nStk.pop();
                a = nStk.top();
                nStk.pop();

                switch(s[i]){
                    case '+':
                        nStk.push(a+b);
                        break;
                    case '-':
                        nStk.push(a-b);
                        break;
                    case '*':
                        nStk.push(a*b);
                        break;
                    case '/':
                        nStk.push(a/b);
                        break;
                    case '%':
                        nStk.push(a%b);
                        break;
                }
            }
        }
        cout << nStk.top() << endl;
        nStk.pop();
        s.clear();
    }
}
