#include <iostream>
using namespace std;

int main() {
    int answer, guess, round = 0;
    srand(time(0));
    answer = rand() % 101;
    //cout << answer;

    do {
        cin >> guess;

        if (guess > 100 || guess < 0) {
            cout << "超出範圍！！\n";
            continue;
        }

        if (answer > guess) cout << "更大\n";
        if (answer < guess) cout << "更小\n";

        round++;
    } while (answer != guess);

    cout << "猜中了！終極密碼是：" << answer << "\n總共猜了：" << round << "次";
}