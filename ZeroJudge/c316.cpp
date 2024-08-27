#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, mi = 0, mj = 0;
    double mxd = -1e9;
    cin >> n;
    vector<int> x, y;
    while (n--) {
        int dx, dy;
        cin >> dx >> dy;
        x.push_back(dx);
        y.push_back(dy);
    }

    for (int i = 0; i < x.size(); i++) {
        for (int j = i+1; j < x.size(); j++) {
            double d = sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
            if (d > mxd) {
                mxd = d;
                mi = i; mj = j;
            }
        }
    }

    cout << mi << ' ' << mj;
}