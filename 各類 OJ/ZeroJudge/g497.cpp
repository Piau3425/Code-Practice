#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, sum = 0, t, pt = 1;
    cin >> n;
    while (n--) {
        cin >> t;
        if (t > pt) sum += (t-pt)*3;
        else sum += (pt-t)*2;
        pt = t;
    }
    cout << sum;
}