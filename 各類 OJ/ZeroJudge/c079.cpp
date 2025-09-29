#include <iostream>
using namespace std;

int total, sum, recy;

int main(){
    while(cin >> total >> recy){
        sum = total;

        while(total/recy > 0){
            sum += total/recy;
            total = total/recy + total%recy;
        }

        cout << sum << endl;
    }
}
