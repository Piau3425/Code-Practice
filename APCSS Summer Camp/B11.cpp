#include <bits/stdc++.h>
using namespace std;

int main(){
    long long t[3];
    cin >> t[0] >> t[1] >> t[2];
    sort(t, t+3);

    if(t[0] + t[1] <= t[2]) cout << "無法形成三角形";
    else if (t[0]*t[0]+t[1]*t[1] == t[2]*t[2]) cout << "直角三角形";
	else if (t[0] == t[1] && t[1] == t[2]) cout << "正三角形";
    else if (t[0] == t[1] || t[1] == t[2]) cout << "等腰三角形";
    else cout << "普通三角形";
}