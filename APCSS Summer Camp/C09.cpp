#include <bits/stdc++.h>
using namespace std;

int main() {
    int save[26] = {}, f = 0, s;
    char c;
    while (cin >> c) save[c-'A']++;
        
    for (int i = 0; i < 26; i++)
        if (save[i]&1) {
            f++;
            s = i;
        }

    if (f > 1) cout << "IMPOSSIBLE";
	else {
		string ans = "";
	    for (int i = 0; i < 26; i++) if (save[i]) ans += string(save[i]/2, char(i+'A'));
	    if (f) ans += char(s+'A');
	    ans += string(ans.rbegin()+f, ans.rend());
	
	    cout << ans;
	}
}