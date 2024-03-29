#include <iostream>
#include <map>
using namespace std;

map<int, bool> mp;
int amount, group = 0, start;
int* f;

int main(){
    cin >> amount;
    f = new int[amount];

    for(int i = 0; i < amount; i++){
        cin >> f[i];
        mp[i] = false;
    }


    for(int i = 0; i < amount; i++){
        if(mp[i])
            continue;

        start = i;
        mp[i] = true;
        for(int j = f[i]; j != start;){
            mp[j] = true;
            j = f[j];
        }

        group++;
    }

    cout << group;
}
