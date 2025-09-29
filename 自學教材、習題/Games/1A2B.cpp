#include <iostream>
#include <bitset>
using namespace std;

int main() {
    string ans = "", input;
    int A, B, round = 0, digit, rnum;
    bool Repeat = true;
    bitset<9999> Noexist(1);

    cin >> digit;

    srand((unsigned)time(NULL));

    while (ans.length() < digit) {
        rnum = rand()%10;
        if (Repeat || Noexist[rnum]) {
            ans += rnum + 48;
            Noexist[rnum] = false;
        }
    }
        
    while (cin >> input) {
        if (input.length() != digit) {
            cout << "input error\n";
            continue;
        }

        bitset<9999> va(0), vb(0);
        A = 0; B = 0;
        round++;

        for (int i = 0; i < digit; i++) 
            if (ans[i] == input[i]) {
                A++;
                va[i] = true;
                vb[i] = true;
            }
                
        for (int i = 0; i < digit; i++) {
            if (va[i]) continue;
            for (int j = 0 ; j < digit; j++) {
                if (vb[j]) continue;
                if (ans[i] == input[j]) {
                    B++;
                    vb[j] = true;
                }
            }
        }

        if (A == digit) break;
        cout << A << 'A' << B << "B\n";
    }

    cout << "Correct!! Number is " << ans << " round = " << round;
}