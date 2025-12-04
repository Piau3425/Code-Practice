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

signed main() { WA();
      int32_t int_arr[0x2e];
      int_arr[0] = 7;
      int_arr[1] = 0x2a;
      int_arr[2] = 0xc;
      int_arr[3] = 0x1b;
      int_arr[4] = 0;
      int_arr[5] = 0x1d;
      int_arr[6] = 0x24;
      int_arr[7] = 0x19;
      int_arr[8] = 0x10;
      int_arr[9] = 0x17;
      int_arr[0xa] = 0x1e;
      int_arr[0xb] = 0xf;
      int_arr[0xc] = 0x21;
      int_arr[0xd] = 1;
      int_arr[0xe] = 5;
      int_arr[0xf] = 0x14;
      int_arr[0x10] = 0xa;
      int_arr[0x11] = 0x11;
      int_arr[0x12] = 8;
      int_arr[0x13] = 0x29;
      int_arr[0x14] = 0x1f;
      int_arr[0x15] = 0x27;
      int_arr[0x16] = 3;
      int_arr[0x17] = 0x18;
      int_arr[0x18] = 0x20;
      int_arr[0x19] = 0xb;
      int_arr[0x1a] = 9;
      int_arr[0x1b] = 0x26;
      int_arr[0x1c] = 0x1a;
      int_arr[0x1d] = 6;
      int_arr[0x1e] = 2;
      int_arr[0x1f] = 0x23;
      int_arr[0x20] = 0x2b;
      int_arr[0x21] = 0x13;
      int_arr[0x22] = 0x25;
      int_arr[0x23] = 0x2c;
      int_arr[0x24] = 4;
      int_arr[0x25] = 0x22;
      int_arr[0x26] = 0xd;
      int_arr[0x27] = 0x15;
      int_arr[0x28] = 0x16;
      int_arr[0x29] = 0xe;
      int_arr[0x2a] = 0x12;
      int_arr[0x2b] = 0x1c;
      int_arr[0x2c] = 0x28;
      int_arr[0x2d] = 0x2d;


    char magic = 19;
    string s; cin >> s;
    char output[46];

    for (int i = 0; i < 46; i++) {
        char result = (s[i*2]-'0')*16, a = s[i*2+1];
        if (isdigit(a)) result += a-'0';
        else result += a-'a'+10;
        output[int_arr[45-i]] = (magic^result);
    }
    //for (int i = 0; i < 46; i++) cout << (output[int_arr[45-i]]);
    cout << output;
}