#include <iostream>
#include <vector>
using namespace std;

int main(){ ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m, killer;
    cin >> n >> m;
    vector<int> v(n+1); 

    for(int i = 0; i <= n; i++)
        v[i] = i+1;
    
    while(m--){
        cin >> killer;
        int target = v[killer];
        if(target && target <= n){
            cout << target << '\n';
            v[killer] = v[target];
            v[target] = 0;
        }
        else
            cout << "0u0 ...... ?\n";
    }
}