#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, m, k, b = 0;
    cin >> n >> m >> k;
    vector<int> v(n);

    for(int i = 0; i < n; i++) v[i] = i+1;
    for(int i = 0; i < k; i++){
        b = (b + m - 1) % v.size();
        v.erase(v.begin() + b);
    }
    b %= v.size();
    cout << v[b];
}