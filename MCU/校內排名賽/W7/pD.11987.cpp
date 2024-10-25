#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<int> anc, sum, sz;

int find(int x) { return (anc[x] == x ? x : anc[x] = find(anc[x])); }

void merge(int p, int q) {
    int a = find(p), b = find(q);
    if (a == b) return;
    if (sz[a] < sz[b]) swap(a, b);
    sz[a] += sz[b];
    sum[a] += sum[b];
    anc[b] = anc[a];
}

void move(int p, int q) {
    int a = find(p), b = find(q);
    if (a == b) return;
    sz[a]--; sz[b]++;
    sum[p] -= p; sum[b] += b;
    anc[p] = find(q);
}

signed main() {
    int n, m;
    cin >> n >> m;
    sum.resize(n+1); anc.resize(n+1); sz.resize(n+1, 1);
    iota(anc.begin(), anc.end(), 0);
    iota(sum.begin(), sum.end(), 0);

    while (m--) {
        int cmd, p, q;
        cin >> cmd;
        if (cmd == 1) {
            cout << "1.\n";
            cin >> p >> q;
            merge(p, q);
        }
        else if (cmd == 2) {
            cout << "2.\n";
            cin >> p >> q;
            move(p, q);
        }
        else if (cmd == 3) {
            cin >> p;
            cout << sz[find(p)] << ' ' << sum[find(p)] << '\n';
        }
        if (cmd == 3) continue;
        for (auto i : anc) cout << i << ' ';
        cout << '\n';
        for (auto i : sz) cout << i << ' ';
        cout << '\n';
        for (auto i : sum) cout << i << ' ';
        cout << "\n\n";
    }
}