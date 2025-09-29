#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> h(n), w(n);
    vector<pair<int, int>> v(n);

    for(int i = 0; i < n; i++)
        cin >> h[i];
    for(int i = 0; i < n; i++)
        cin >> w[i];
    for(int i = 0; i < n; i++)
        v[i] = {h[i]*w[i], i};
    
    sort(v.begin(), v.end());

    cout << h[v[0].second] << " " << w[v[0].second];
}