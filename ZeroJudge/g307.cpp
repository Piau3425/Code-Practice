#include <iostream>
#include <vector>
#include <algorithm>
#define all(x) x.begin(), x.end()
using namespace std;


int main(){ ios_base::sync_with_stdio(0); cin.tie(0);
    int n, k, t, f = 1;
    cin >> n >> k >> t;

    for(int i = 0; i < n; i++){
        int sum = 0;
        vector<int> v(k);
        for(auto &i : v) cin >> i;
        sort(all(v));
        for(int i = 1; i < v.size() - 1; i++) sum += v[i];
        if(sum/(k-2) >= t){
            cout << i << '\n';
            f = 0;
        }
    }

    if(f) cout << "A is for apple.";
}