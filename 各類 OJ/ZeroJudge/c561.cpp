#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> v;
    for(int i = 0; i < n; i++){
        string input;
        cin >> input;
        reverse(input.begin(), input.end());
        v.push_back(stoi(input));
    }
    
    sort(v.begin(), v.end(), greater<int>());

    cout << v[0];
}