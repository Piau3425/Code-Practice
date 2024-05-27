#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n, m, index, sum;
    cin >> n;
    while(n--){
        cin >> m;
        vector<int> v(m);
        sum = 0;
        for(int i = 0; i < m; i++)
            cin >> v[i];
        sort(v.begin(), v.end());

        index = (m/2)-1 + (m%2);
        for(int i = 0; i < m; i++)
            sum += abs(v[index] - v[i]);

        cout << sum << '\n';
    }
}