#include <bits/stdc++.h>
using namespace std;

struct d {
    int p[6] = {1, 2, 6, 5, 4, 3};
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<d> v(n);

    while (m--) {
        int a, b;
        cin >> a >> b;
        if (b == -1) {
            a--;
            swap(v[a].p[0], v[a].p[5]);
            swap(v[a].p[5], v[a].p[2]);
            swap(v[a].p[2], v[a].p[4]);
        }
        else if (b == -2) {
            a--;
            swap(v[a].p[0], v[a].p[3]);
            swap(v[a].p[3], v[a].p[2]);
            swap(v[a].p[2], v[a].p[1]);
        }
        else swap(v[a-1], v[b-1]);
    }

    for (int i = 0; i < n; i++) cout << (i ? " " : "") << v[i].p[0];
}