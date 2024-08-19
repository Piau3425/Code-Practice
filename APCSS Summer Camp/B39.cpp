#include <bits/stdc++.h>
using namespace std;

int main(){
    int k, w, s, e;
    cin >> k >> w >> s >> e;
    cout << (k > 2)*(k-2)*5 + 20 + w/2*5 + (e >= 19 && e <= 23)*(185+(e-19)*10);
}