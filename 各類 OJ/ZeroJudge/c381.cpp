#include <iostream>
using namespace std;

int main(){
    string str, tmp;
    int n, m, idx;
    while(1){ ios::sync_with_stdio(0); cin.tie(0);
        str = "";
        cin >> n >> m;
        if(!n && !m)
            break;

        while(n--){
            cin >> tmp;
            str += tmp;
        }

        while(m--){
            cin >> idx;
            cout << str[idx-1];
        }
        cout << '\n';
    }
}