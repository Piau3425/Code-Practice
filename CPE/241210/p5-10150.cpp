#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define WA() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define sz(x) ((int)(x).size())

int main() { WA();
    string s;
    vector<string> word;
    while (getline(cin, s) && s != "") word.pb(s);

    map<string, vector<string>> mp;
    for (auto &a : word) for (auto &b : word) if (sz(a) == sz(b)) {
        int diff = 0;
        for (int i = 0; i < sz(a) && diff < 2; i++) diff += a[i] != b[i];
        if (diff == 1) mp[a].pb(b);
    }

    string sta, end;
    int t = 0;
    while (cin >> sta >> end) {
        if (t++) cout << '\n';
        map<string, int> vis;
        map<string, string> path;
        queue<string> q;
        q.push(sta), vis[sta] = true;

        while (!q.empty()) {
            string now = q.front(); q.pop();
            if (now == end) break;
            for (auto i : mp[now]) if (!vis[i]) vis[i] = true, q.push(i), path[i] = now;
        }

        string ans;
        if (path[end] == "") cout << "No solution.\n";
        else {
            while (end != sta) ans += string(end.rbegin(), end.rend()) + "\n", end = path[end];
            cout << sta + string(ans.rbegin(), ans.rend()) << '\n';
        }
    }
}