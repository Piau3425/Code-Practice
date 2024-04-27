#include <iostream>
using namespace std;

int main(){
    int n;
    while(cin >> n){
        int maxx;
        for(int i = 0; i < n; i++){
            int tmp;
            cin >> tmp;
            maxx = max(maxx, tmp);
        }

        cout << maxx << "\n";
    }
}


