#include <iostream>
using namespace std;

int main(){
    string vac;
    int sum = 0;
    cin >> vac;

    for(int i = 0; i < vac.length(); i++)
        sum += vac[i] - 'A' + 1;

    cout << sum;
}