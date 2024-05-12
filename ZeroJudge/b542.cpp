#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool bs(int k, vector<int>& h, int l, int r){
    if(h[r]-h[l] < k)
        r++;
    else if(h[r]-h[l] > k)
        l++;
    else if(l == r)
        r++;
    
    cout << l << " " << r << endl;
    if(h[r]-h[l] == k)
        return true;
    else if(r <= h.size()-1)
        return bs(k, h, l, r);
    else
        return false;
}

int main(){
    vector<int> height;
    int n, m, input;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> input;
        height.push_back(input);
    }

    sort(height.begin(), height.end());
    for(int i = 0; i < m; i++){
        int key;
        cin >> key;

        if(bs(key, height, 0, 1))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}