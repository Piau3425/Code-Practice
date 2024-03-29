#include <iostream>
#include <stack>

using namespace std;

stack<int> stk;
int n, temp;

int main(){
    cin >> n;
    int* ary;
    ary = new int[n];

    for(int i = 0; i < n; i++)
        cin >> ary[i];
    for(int i = 0; i < n-1; i++){
        for(int i = 0; i < n-1-i; i++){
            if(ary[i] > ary[i+1]){
                temp = ary[i];
                ary[i] = ary[i+1];
                ary[i+1] = temp;
            }
        }
    }

    for(int i = 0; i < n; i++){
        cout << ary[i] << " ";
        stk.push(ary[i]);
    }

    cout << endl << stk.top();
    temp = stk.top();
    stk.pop();
    while(!stk.empty()){
        if(stk.top() != temp){
            cout << " " << stk.top();
            temp = stk.top();
            stk.pop();
        }
        else
            stk.pop();
    }


}
