#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define se second
#define INF LONG_LONG_MAX/1000
#define WA() cin.tie(0)->sync_with_stdio(0)
#define all(x) (x).begin(), (x).end()
#define int long long
#define PII pair<int, int>

string r, p;
int n;

bool cmp(vector<string> a, vector<string> b) {
    int ka, kb, wa, wb;
    for (int i = 0; i < a.size(); i++) if (a[i] == p) {
        ka = i;
        break;
    }
    for (int i = 0; i < b.size(); i++) if (b[i] == p) {
        kb = i;
        break;
    }
    if (r == "L") {
        vector<string> la, lb;
        for (int i = 0; i < ka; i++) la.pb(a[i]);
        while (la.size() < n) la.pb("");
        for (int i = 0; i < kb; i++) lb.pb(b[i]);
        while (lb.size() < n) lb.pb("");
        return la < lb;
/*         wa = 0, wb = 0;
        while (wa < ka && wb < kb) {
            if (a[wa] != b[wb]) return a[wa] < b[wb];
            wa++, wb++;
        } */
    }
    else {
        vector<string> la, lb;
        for (int i = ka+1; i < a.size(); i++) la.pb(a[i]);
        while (la.size() < n) la.pb("");
        for (int i = kb+1; i < b.size(); i++) lb.pb(b[i]);
        while (lb.size() < n) lb.pb("");
        return la < lb;
/*         wa = ka + 1, wb = kb + 1;
        while (wa < a.size() && wb < b.size()) {
            if (a[wa] != b[wb]) return a[wa] < b[wb];
            wa++, wb++;
        } */
    }
}

signed main() {
    cin >> p >> n >> r;
    for (auto &i : p) i = tolower(i);
    vector<string> v;
    string tmp;
    while (cin >> tmp) {
        for (auto &i : tmp) i = tolower(i);
        v.emplace_back(tmp);
    }
    vector<vector<string>> ans;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == p) {
            vector<string> k;
            int sta = i, ed = i;
            while (sta-1 >= 0 && i-(sta-1) <= n) sta--;
            while (ed+1 < v.size() && (ed+1)-i <= n) ed++;
            for (; sta <= ed; sta++) k.pb(v[sta]);
            ans.pb(move(k));
        }
    }
    sort(all(ans), cmp);
    for (auto &k : ans) {
        for (int j = 0; j < k.size(); j++) {
            if (k[j] == p) for (auto &i : k[j]) cout << char(toupper(i));
            else for (auto &i : k[j]) cout << char(tolower(i));
            cout << " \n"[j+1 == k.size()];
        }
    }
}