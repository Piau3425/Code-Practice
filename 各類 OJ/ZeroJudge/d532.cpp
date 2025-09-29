#include <iostream>
using namespace std;

bool isLeap(int y){
    return (!(y % 4) && y % 100) || !(y % 400);
}

int main(){
    int start, end, total = 0;
    cin >> start >> end;
    for(int i = start; i <= end; i++)
        total += isLeap(i);

    cout << total;
}