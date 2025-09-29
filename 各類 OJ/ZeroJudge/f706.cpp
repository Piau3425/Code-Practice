#include <bits/stdc++.h>
using namespace std;

int main(){
    int h, m, s, t;
    cin >> h >> m >> s >> t;
    t += 24;
    m += (t&1) * 30;
    h += t+(t/2) + m/60;
    cout << h%36 << ':'<< setw(2) << setfill('0') << m%60 << ':' << setw(2) << setfill('0') << s;
}