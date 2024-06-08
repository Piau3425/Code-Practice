#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int loc, food, l = 0, r = 0, input, minn = 1e9, maxx = -1e9;
    cin >> loc >> food;
    while(food--){
        cin >> input;
        if(input > loc){
            r++;
            maxx = max(input, maxx);
        }
        else{
            l++;
            minn = min(input, minn);
        }
    }

    if(l > r)
        cout << l << " " << minn;
    else
        cout << r << " " << maxx;
}