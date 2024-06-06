/*WA : 7*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<long long, char>> v(3);

int main(){
    v[0].second = 'A';
    v[1].second = 'B';
    v[2].second = 'C';
    while(cin >> v[0].first >> v[1].first >> v[2].first){
        sort(v.begin(), v.end());

        if(v[0].first + v[1].first > v[2].first)
            cout << v[1].second << '\n';
        else
            cout << v[2].second << '\n';
    }
}