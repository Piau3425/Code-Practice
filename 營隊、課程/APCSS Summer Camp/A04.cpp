#include <iostream>
using namespace std;

int main(){
    int h1, h2, m1, m2;
    cin >> h1 >> m1 >> h2 >> m2;
    cout << (h2-h1)*3600 + (m2-m1)*60;
}