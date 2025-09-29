#include <iostream>
using namespace std;

int AC, maxx;

int main(){
    for(int i = 0; i < 3; i++){
        cin >> AC;
        maxx = max(AC, maxx);
    }
    cout << maxx;
}
