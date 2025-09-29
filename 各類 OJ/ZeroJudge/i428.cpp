#include <iostream>
#include <cstdlib>
using namespace std;

int* x;
int* y;
int maxx, minn, distence, loop;

int main(){
    cin >> loop;

    x = new int[loop];
    y = new int[loop];

    for(int i = 0; i < loop; i++)
        cin >> x[i] >> y[i];

    distence = abs(x[0] - x[1]) + abs(y[0] - y[1]);
    maxx = distence;
    minn = distence;

    for(int i = 0; i < loop-1; i++){
        distence = abs(x[i] - x[i+1]) + abs(y[i] - y[i+1]);
        maxx = max(maxx, distence);
        minn = min(minn, distence);
    }

    cout << maxx << " " << minn;
}
