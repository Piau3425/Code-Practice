#include <bits/stdc++.h>
using namespace std;

bool cmp(int a, int b) {
    if (!(a%7) && !(b%7)) return a%70 > b%70;
    else if (a%7 && b%7) return a%77 < b%77;
    else return !(a%7);
}

int main(){
    vector<int> v;
    int n, mx;
    cin >> mx;
    while(cin >> n && n) if (cmp(n, mx)) mx = n;
    cout << mx;
}