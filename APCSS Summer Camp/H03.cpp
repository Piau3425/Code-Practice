#include <iostream>
#include <vector>
using namespace std;

int main(){
    int idx = 0, len, total = 0, maxx = -1e9;
    cin >> len;
    vector<int> v(len);
    for(int i = 0; i < len; i++)
        cin >> v[i];
        
    while(idx < len){
        if(total == 0 || v[idx] < v[idx-1]){
            total++;
            idx++;
        }
        else{
            maxx = max(total, maxx);
            total = 0;
        }
    }

    maxx = max(total, maxx);
    cout << maxx;
}