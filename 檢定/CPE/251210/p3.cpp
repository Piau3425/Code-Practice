#include <bits/stdc++.h> // 萬用標頭檔，省去 iostream, string 等
using namespace std;

// 對應 0-9 的 Bitmask (十進位)
// Bit 定義: 0:上, 1:左上, 2:右上, 3:中, 4:左下, 5:右下, 6:下
// 例如 0 (119) = 1110111 (二進位, LSB在前) -> 缺 bit 3 (中)
int t[] = {119, 36, 93, 109, 46, 107, 123, 37, 127, 111};

int main() {
    int s, r, i, z, d, k, v;
    string n;
    while (cin >> s >> n && s) {
        // r 掃描每一行, 每次迴圈結束換行
        for (r = 0; r < 2 * s + 3; r++, cout << '\n') {
            for (i = 0; i < n.size(); i++) {
                if (i) cout << ' '; // 數字間隔
                
                d = t[n[i] & 15];   // 取出該數字的 mask (char轉int, '0'是48, &15後變0)
                k = r / (s + 1);    // 區域索引: 0(上區), 1(下區/中), 2(底)
                v = r % (s + 1);    // 0代表橫線, 非0代表直線
                
                // 左邊字符 (直線時看 bit 3k+1)
                cout << (v ? (d >> 3 * k + 1 & 1 ? '|' : ' ') : ' ');
                
                // 中間字串 (橫線時看 bit 3k)
                for (z = 0; z++ < s;) 
                    cout << (v ? ' ' : (d >> 3 * k & 1 ? '-' : ' '));
                
                // 右邊字符 (直線時看 bit 3k+2)
                cout << (v ? (d >> 3 * k + 2 & 1 ? '|' : ' ') : ' ');
            }
        }
        cout << '\n'; // 每個 Case 的結尾空行
    }
}