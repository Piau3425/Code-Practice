#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n, l, r, val = 0, save, total = 0;
    cin >> n;
    vector<pair<int, int>> coord;
    while(n--){
        cin >> l >> r;
        coord.push_back({l, 1});
        coord.push_back({r + 1, -1});
    }

    sort(coord.begin(), coord.end());

    for(int i = 0; i < coord.size(); i++){
        val += coord[i].second;

        if(coord[i].second == 1 && val == 1)
            save = coord[i].first;

        if(coord[i].second == -1 && val == 0)
            total += coord[i].first - save -1;
    }

    cout << total;
}