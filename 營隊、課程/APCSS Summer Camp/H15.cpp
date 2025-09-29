#include <bits/stdc++.h>
using namespace std;

int main(){
    int amount, group = 0, start;
    cin >> amount;
    vector<int> f(amount);
    vector<bool> vis(amount, false);

    for(auto &i : f) cin >> i;

    for(int i = 0; i < amount; i++){
        if(vis[i]) continue;

        start = i;
        vis[i] = true;
        for(int j = f[i]; j != start;){
            vis[j] = true;
            j = f[j];
        }

        group++;
    }

    cout << group;
}
