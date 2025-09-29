#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n, worstc = -1, bestc = -1;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];

    sort(v.begin(), v.end());

    for(int i = 0; i < v.size(); i++)
        cout << v[i] << " \n"[i+1 == v.size()];

    for(int i = 0; i < v.size(); i++){
        if(v[i] < 60)
            bestc = max(bestc, v[i]);
        if(v[i] >= 60 && worstc == -1)
            worstc = v[i];
    }

    if(v[0] >= 60)
        cout << "best case\n";  
    else
        cout << bestc << '\n';

    if(v[v.size()-1] < 60)
        cout << "worst case\n";
    else
        cout << worstc << '\n';
        
}