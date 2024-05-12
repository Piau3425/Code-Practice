#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<std::pair<int, int>> v;
    v.push_back(pair<int, int> (1, 2));
    v.emplace_back(1, 2);

    for(auto i : v)
        cout << i.first << " " << i.second << endl;
}