#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int main(){
    int n, tmp;
    set<int> s;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> tmp;
        s.insert(tmp);
    }
    
    cout<< s.size() << "\n";
    for(int i : s)
        cout << i << " ";
}