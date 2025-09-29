#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<int> anc, sum, sz;

int find(int x) { return (anc[x] == x ? x : anc[x] = find(anc[x])); }

/*
void list_all() {
    for (auto i : anc) cout << i << ' ';
    cout << '\n';
    for (auto i : sz) cout << i << ' ';
    cout << '\n';
    for (auto i : sum) cout << i << ' ';
    cout << "\n\n";
}
*/

void merge(int p, int q) {
    int a = find(p), b = find(q);
    if (a == b) return;
    sz[b] += sz[a];
    sum[b] += sum[a];
    anc[a] = b;
}

void move(int p, int q) {
    int a = find(p), b = find(q);
    if (a == b) return;
    sz[a]--; sz[b]++; // 可以改用 sz[p]
    sum[a] -= p; sum[b] += p; // 可以改用 sum[p]
    anc[p] = b;
}

signed main() {
    int n, m;
    while (cin >> n >> m) {
        sum.resize(2*n+2); anc.resize(2*n+2); sz.resize(2*n+2, 1);

        for (int i = 1; i <= n; i++) {
            anc[i] = anc[i+n] = i+n;
            sum[i] = sum[i+n] = i;
        }
        
        while (m--) {
            int cmd, p, q;
            cin >> cmd;
            if (cmd == 1) {
                //cout << "1.\n";
                cin >> p >> q;
                merge(p, q);
            }
            else if (cmd == 2) {
                //cout << "2.\n";
                cin >> p >> q;
                move(p, q);
            }
            else if (cmd == 3) {
                cin >> p;
                cout << sz[find(p)] << ' ' << sum[find(p)] << '\n';
            }

            /*
            if (cmd == 3) continue;
            list_all();
            */
        }
        anc.clear(); sz.clear(); sum.clear();
    }
}