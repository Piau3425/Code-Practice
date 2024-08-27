#include <iostream>
using namespace std;

/*
0 → 石頭
1 → 剪刀
2 → 布
*/

int main() {
    int bot, user;
    string choice[3] = {"石頭\n", "剪刀\n", "布\n"};
    cout << "0 → 石頭\n1 → 剪刀\n2 → 布\n祝您遊玩愉快~~\n";
    
    while (cin >> user) {
        srand(time(0));
        bot = rand() % 3;
        
        if (user > 2 || user < 0) {
            cout << "超出選擇範圍！！\n";
            continue;
        }
        cout << "你的選擇：" << choice[user];
        cout << "電腦的選擇：" << choice[bot];

        if (user == bot) {
            cout << "結果：平手！\n";
        } else if ((user + 1) % 3 == bot) {
            cout << "結果：勝利！\n";
        } else {
            cout << "結果：敗北！\n";
        }
        
        cout << "--------------------\n";
    }
}