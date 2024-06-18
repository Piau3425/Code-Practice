#include <iostream>
using namespace std;

int main(){
    int n, m, tmp, minn, strong = -1e9;
    cin >> n;
    while(n--){
        minn = 1e9;
        cin >> m;
        while(m--){
            cin >> tmp;
            if(tmp < minn) minn = tmp;
        }
        if(minn > strong) strong = minn;
    }

    cout << strong;
}