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
    int start, end, maxx = -1e9;
    while(cin >> start >> end){
        cycle = 0;
        for(int i = start; i <= end; i++)
            maxx = max(check(i), maxx);
        cout << start << " " << end << " " << maxx << '\n';
    }
}