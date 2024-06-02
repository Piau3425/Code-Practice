/*TLE*/

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, maxx;
    cin >> n;
    vector<string> v(n);
    
    for(int i = 0; i < n; i++)
        cin >> v[i];
    
    for(int i = 0; i < n; i++)
        maxx = max(maxx, int(v[i].length()));

    for(int i = 0; i < maxx; i++){
        for(int j = 0; j < n; j++){
            if(!isdigit(v[j][i]))
                cout << v[j][i];
        }
    }
}