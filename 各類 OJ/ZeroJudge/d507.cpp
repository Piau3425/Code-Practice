#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int i[3];
    cin >> i[0] >> i[1] >> i[2];
    sort(i, i+3);

    i[0] *= i[0]; i[1] *= i[1]; i[2] *= i[2];
    if(i[0] + i[1] < i[2])
        cout << "obtuse ";
    else if(i[0] + i[1] > i[2])
        cout << "acute ";
    else
        cout << "right ";
    
    cout << "triangle";
}