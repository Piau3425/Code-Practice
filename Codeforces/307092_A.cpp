#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, m, tmp, lidx = 0, ridx = 0;
    cin >> n >> m;
    vector<int> a(n), b(m), merge;

    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < m; i++)
        cin >> b[i];
    a.push_back(1e9);
    b.push_back(1e9);

    while(lidx < a.size()-1 || ridx < b.size()-1){
        if(a[lidx] < b[ridx]){
            merge.push_back(a[lidx]);
            lidx++;
        }
        else{
            merge.push_back(b[ridx]);
            ridx++;
        }
    }

    for(int val : merge)
        cout << val << ' ';
}