#include <iostream>
using namespace std;

int total, garbage;

int main(){
    cin >> total;
    int gar[total] = {0};
    for(int i = 0; i < 3; i++){
        cin >> garbage;
        gar[garbage-1] = 1;
    }

    for(int i = total; i >= 1; i--){
        if(gar[i-1] == 0)
            cout << "No. " << i << endl;
    }
}
