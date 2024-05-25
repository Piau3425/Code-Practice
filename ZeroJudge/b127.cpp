#include <iostream>
#include <vector>
using namespace std;

long long fN(vector<long long>& a, int m){
    if(m == 1)
        return 1;
    else if(m == 2)
        return 2;
    else
        return a[m-1] + a[m-2];
}

int main(){
    int m;
    vector<long long> a(60);
    a[2] = 2; a[1] = 1;
    for(int i = 3; i < 60; i++){
        a[i] = a[i-1] + a[i-2];
    }
    while(cin >> m){
        cout << fN(a, m) << endl;
    }
}