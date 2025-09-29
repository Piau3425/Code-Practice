#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main(){
    vector<int> s1;
    set<int> s2;
    int n, tmp;
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> tmp;
        s1.push_back(tmp);
        s2.insert(tmp);
    }

    sort(s1.begin(), s1.end());
    for(int i = 0; i < s1.size(); i++)
        cout << s1[i] << " ";
    cout << '\n';

    for(auto iter = s2.rbegin(); iter != s2.rend(); iter++)
        cout << *iter << " ";

}
