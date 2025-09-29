#include <bits/stdc++.h>
using namespace std;

int main(){
    int x, y, n, mx, my;
    double mind = 1e9;
    cin >> x >> y >> n;
    while (n--) {
        int fx, fy;
        cin >> fx >> fy;
        if (sqrt((x-fx)*(x-fx) + (y-fy)*(y-fy)) < mind) {
            mx = fx; my = fy;
            mind = sqrt((x-fx)*(x-fx) + (y-fy)*(y-fy));
        }
    }
    cout << mx << ' ' << my;
}