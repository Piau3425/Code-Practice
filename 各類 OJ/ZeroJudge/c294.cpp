#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int t[3];
    cin >> t[0] >> t[1] >> t[2];
    sort(t, t+3);
    cout << t[0] << " " << t[1] << " " << t[2] << '\n';

    if(t[0] + t[1] <= t[2])
        cout << "No";
    else if(t[0]*t[0]+t[1]*t[1] > t[2]*t[2])
        cout << "Acute";
    else if(t[0]*t[0]+t[1]*t[1] < t[2]*t[2])
        cout << "Obtuse";
    else
        cout << "Right";
}