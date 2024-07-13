#include <iostream>
using namespace std;

int main() {

    int max, rnum, input = -1e9, round = 0;
    cin >> max;

    srand((unsigned)time(NULL));

    rnum = rand() % max;
    cout << rnum;

    while (rnum != input) {
        round++;
        cin >> input;

        if (input > max) {
            cout << "out of range\n";
            continue;
        }

        if (rnum > input) cout << "Bigger\n";
        if (rnum < input) cout << "Smaller\n";
    }

    cout << "Pass, the code is " << input << " round = " << round;
}