#include <iostream>
#include <set>
using namespace std;

int main(){
    int n;
    set<int> s;
    cin >> n;
    for(int i = 1; i <= n; i++)
        s.insert(i);

    for(int i = 0; i < 3; i++){
        int tmp;
        cin >> tmp;
        s.erase(tmp);
    }

    for(auto i = s.rbegin(); i != s.rend(); i++)
        cout << "No. " << *i << "\n";
}