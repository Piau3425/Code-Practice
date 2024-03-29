#include <iostream>
using namespace std;

int num;

int main(){
    while(cin >> num)
        cout << num/3+(num%3!=0) << endl;
}
