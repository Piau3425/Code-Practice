#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, input;
    cin >> n;
    vector<int> c(n), e(n), cc, ce;
    
    for(int i = 0; i < n; i++)
        cin >> c[i];
    for(int i = 0; i < n; i++)
        cin >> e[i];

    for(int i = 0; i < n; i++){
        if(c[i] > e[i])
            cc.push_back(i+1);
        else
            ce.push_back(i+1);
    }

    if(!cc.empty()){
        for(int i = 0; i < cc.size(); i++)
            cout << cc[i] << " ";
    }
    else
        cout << "-1";
    cout << '\n';

    if(!ce.empty()){
        for(int i = 0; i < ce.size(); i++)
            cout << ce[i] << " ";
    }
    else
        cout << "-1";
    cout << '\n';
}
