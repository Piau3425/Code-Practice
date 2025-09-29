#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    while(cin >> n && n){
        while(1){
            vector<int> A(n), B(n);
            cin >> A[0];
            if(A[0] == 0)
                break;

            for(int i = 1; i < n; i++)
                cin >> A[i];
            for(int i = 0; i < n; i++)
                B[i] = A[A[i]-1];

            stack<int> sta;
            int j = 0;
            for(int i = 0; i < n; i++){
                sta.push(A[i]);
                while(!sta.empty() && sta.top() == B[j]){
                    sta.pop();
                    j++;
                }
            }

            if(sta.empty())
                cout << "Yes\n";
            else
                cout << "No\n";
        }
        cout << '\n';
    }
}
