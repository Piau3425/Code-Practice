#include <bits/stdc++.h>
using namespace std;

bool check(int n, int k) {
    if (n == 0) return false;
    if (n%10 == k) return true;
    return check(n/10, k);
}

int main(){
    int n, k;
    cin >> n >> k;
    if (!(n%k) || check(n, k)) cout << "YES";
    else cout << "NO";
}