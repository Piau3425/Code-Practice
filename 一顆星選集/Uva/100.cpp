#include <iostream>
using namespace std;

int cycle;

int check(int input){
    cycle++;
    if(!(input-1))
        return cycle;
    else if(input&1)
        return check(input*3 + 1);
    else
        return check(input/2);
}

int main(){
    int start, end, maxx = -1e9, l, r;
    while(cin >> start >> end){
        l = min(start, end);
        r = max(start, end);
        maxx = 0;
        for(int i = l; i <= r; i++){
            cycle = 0;
            maxx = max(check(i), maxx);
        }
        cout << start << " " << end << " " << maxx << '\n';
    }
}