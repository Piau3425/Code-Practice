#include <iostream>
using namespace std;

int row, column;

int main(){
    while(cin >> row >> column)
        cout << row*column-1 << endl;

}
