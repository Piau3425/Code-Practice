#include <iostream>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    cout << (m-n)/2+(m%2 == 0 || n%2 == 0);
}