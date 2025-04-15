#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define se second
#define INF LONG_LONG_MAX/1000
#define WA() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define int long long
#define PII pair<int, int>

vector<vector<int>> v;
PII locA, locB;

int find(int x) {

}

int monto(int a, int b) {
    
    for (int i = v[a].size()-1; i > loca; i++) v[v[a][i]].pb(i);
}

int mover(int a, int b) {

}

int ponto(int a, int b) {

}

int pover(int a, int b) {

}

signed main() { WA();
    int n; cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++) v[i].pb(i);
    string cmd, cmd2;
    while (cin >> cmd, cmd != "quit") {
        int a, b;
        cin >> a >> cmd2 >> b;
        if (cmd == "move") {
            if (cmd2 == "onto")
            else
        }
        else {
            if (cmd2 == "onto")
            else
        }
    }
}