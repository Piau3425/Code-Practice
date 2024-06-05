#define ll long long
#include <iostream>
using namespace std;

int solve(ll n, ll m){
    if(n < m*2)
        return 1;
    if(n & 1)
        return solve((n-1)/2, m) + solve((n+1)/2, m);
    else
        return solve(n/2, m) + solve(n/2, m);
}

int main(){ ios_base::sync_with_stdio(0); cin.tie(0);
    ll n, m;
    while(cin >> n >> m){
        cout << (n >= m ? solve(n, m) : 0) << '\n';
    }
}