#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;
int len;

void lovesearch(vector<int> s, int idx){
    if(s.size() == len){
        for(int i = 0; i < s.size(); i++)
            cout << s[i] << ' ';
        cout << '\n';
        return;
    }

    if(idx >= v.size())
        return;
    
    s.push_back(v[idx++]);
    lovesearch(s, idx);
    s.pop_back();
    lovesearch(s, idx);
}

int main(){
    int n;
    while(cin >> n && n != 0){
        v.clear();
        v.resize(n);
        for(int i = 0; i < n; i++)
            cin >> v[i];
        sort(v.begin(), v.end());
        cin >> len;

        vector<int> emty;
        lovesearch(emty, 0);
        cout << '\n';
    }
}