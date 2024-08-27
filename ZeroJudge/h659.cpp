#include <bits/stdc++.h>
using namespace std;

int main(){
    int k, w, s, e, sum;
    cin >> k >> w >> s >> e;
    sum = (k > 2)*(k-2)*5 + 20 + w/2*5;
    for (int i = max(s+1, 19); i <= e; i++) {
    	sum += 185+(i >= 19)*(i-19)*10;
    }
    cout << sum;
}