#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int k;
    cin >> k;
    int total = 1<<k;
    if(pow(sqrt(total)/2, 2)*4 == total){
        for(int i = 0; i < 4; i++)
            cout << sqrt(total)/2 << " ";
    }
    else
        cout << "0";
}
