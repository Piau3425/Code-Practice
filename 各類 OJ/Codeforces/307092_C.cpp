#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*Linear_Search TLE on test 13, after using Binary_Search WA*/

int main(){
    int n, m, lidx = 0, ridx = 0, pairs = 0;
    cin >> n >> m;
    vector<int> a(n), b(m);

    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < m; i++)
        cin >> b[i];

    for(int i = 0; i < n; i++){
        lidx = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
        ridx = upper_bound(b.begin(), b.end(), a[i]) - b.begin();
        
        if(lidx < m && b[lidx] == a[i]) pairs += ridx - lidx;
        //cout << lidx << ' ' << ridx << '\n';
    }

    cout << pairs;
}