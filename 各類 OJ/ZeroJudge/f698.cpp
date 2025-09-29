#include <iostream>
#include <cstdlib>
#include <stack>
#include <string>
using namespace std;

stack<int> nStk;
string s;
int num, a, b, temp = 1;

int main(){
    getline(cin, s);

    for(int i = 0; s[i] != '\0'; i++){
        if(isdigit(s[i]) || (s[i] == '-' && isdigit(s[i+1]))){
            if(s[i] == '-'){
                temp = -1;
                i++;
            }
            num = num*10 + (s[i]-'0');
            i++;
            while(s[i] != ' '){
                if(s[i] == '\0' && nStk.empty()){
                    cout << num;
                    return 0;
                }
                num = num*10 + (s[i]-'0');
                i++;
            }
            num *= temp;
            nStk.push(num);
            num = 0;
            temp = 1;
        }
        if(ispunct(s[i]) && s[i] != ' '){
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
            }
        }
    }
    cout << nStk.top();
}
