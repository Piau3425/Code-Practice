#include <iostream>
using namespace std;

int current, target;

int main(){
    cin >> current >> target;

    cout << (100-(current-target))%100;
}
