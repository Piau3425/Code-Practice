#include <iostream>
#include <sstream>
#include <stack>
#include <queue>
using namespace std;

int main(){
    int amount;
    string input;
    while(cin >> amount && amount != 0){
        cin.ignore();
        while(getline(cin, input) && input != "0"){
            int train = 1;
            stack<int> s;
            queue<int> q;
            stringstream ss;
            ss.str(input);
            int tmp;
            while(ss >> tmp)
                q.push(tmp);
            
            while(train <= amount){
                s.push(train);
                while(!s.empty() && s.top() == q.front()){
                    s.pop();
                    q.pop();
                }
                train++;
            }
            
            if(q.empty())
                cout << "Yes\n";
            else
                cout << "No\n";
        }
        cout << '\n';
    }
}