#include <bits/stdc++.h>
using namespace std;

int main(){
    int start, end, h, m, cnt;
    cin >> h >> m;
    start = h*3600 + m*60;
    cin >> h >> m;
    end = h*3600 + m*60;
    cin >> h >> m;
    cnt = h*3600 + m*60;

    if (cnt >= start && cnt <= end) cout << "Learning";
    else cout << "Break";
}