#include <bits/stdc++.h>
using namespace std;

int main() {
    int user, bot;
    string choice[3] = {"���Y\n", "�ŤM\n", "��\n"};
    cout << "0 �� ���Y\n1 �� �ŤM\n2 �� ��\n���z�C���r��~~\n";
    while (cin >> user) {
        srand(time(0));
        bot = rand() % 3;
        if (user > 2 || user < 0) {
            cout << "�W�X��ܽd��I�I\n";
            continue;
        }
        cout << "�A����ܡG" << choice[user];
        cout << "�q������ܡG" << choice[bot];

        if (user == bot) cout << "���G�G����I\n";
        else if ((user + 1) % 3  == bot) cout << "���G�G�ӧQ�I\n";
        else cout << "���G�G�ѥ_�I\n";

        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    }
}
