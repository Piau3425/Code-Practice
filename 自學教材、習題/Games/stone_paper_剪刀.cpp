#include <iostream>
using namespace std;

/*
0 → 石頭
1 → 剪刀
2 → 布
*/

int main() {
    int bot, user;
    cout << "0 → 石頭\n1 → 剪刀\n2 → 布\n祝您遊玩愉快~~\n";

    while (cin >> user) {
        srand(time(0));
        bot = rand() % 3;
        
        if (user > 2 || user < 0) {
            cout << "超出選擇範圍！！\n";
            continue;
        }

        if (user == 0) {
            cout << "你的選擇：石頭\n";
        }
        if (user == 1) {
            cout << "你的選擇：剪刀\n";
        }
        if (user == 2) {
            cout << "你的選擇：布\n";
        }
        if (bot == 0) {
            cout << "電腦的選擇：石頭\n";
        }
        if (bot == 1) {
            cout << "電腦的選擇：石頭\n";
        }
        if (bot == 2) {
            cout << "電腦的選擇：石頭\n";
        }

        if (user == 0 && bot == 1) {
            cout << "結果：勝利！\n";
        }
        if (user == 1 && bot == 2) {
            cout << "結果：勝利！\n";
        }
        if (user == 2 && bot == 0) {
            cout << "結果：勝利！\n";
        }

        if (user == 1 && bot == 0) {
            cout << "結果：敗北！\n";
        }
        if (user == 2 && bot == 1) {
            cout << "結果：敗北！\n";
        }
        if (user == 0 && bot == 2) {
            cout << "結果：敗北！\n";
        }
        
        if (user == bot) {
            cout << "結果：平手！\n";
        }
        cout << "--------------------\n";
    }
}