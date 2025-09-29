#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main(){
    int amount;
    string input;
    while(cin >> amount && amount != 0){
        vector<int> need(amount);
        while(cin >> need[0] && need[0] != 0){
            for(int i = 1; i < amount; i++)
                cin >> need[i];
            int train = 1, index = 0;
            stack<int> s;
            
            while(train <= amount){
                s.push(train);
                while(!s.empty() && s.top() == need[index]){
                    s.pop();
                    index++;
                }
                train++;
            }
            
            if(s.empty())
                cout << "Yes\n";
            else
                cout << "No\n";
        }

        cout << '\n';
    }
}