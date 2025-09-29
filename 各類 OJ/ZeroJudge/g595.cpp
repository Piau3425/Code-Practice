#include <iostream>
using namespace std;

int loop, sum = 0;
int* h;

int main(){
    cin >> loop;
    h = new int[loop];

    for(int i = 0; i < loop; i++)
        cin >> h[i];

    for(int i = 0; i < loop; i++){
        if(h[i] == 0){
            if(i == 0)
                sum += h[i+1];
            else if(i == loop-1)
                sum += h[i-1];
            else
                sum += min(h[i-1], h[i+1]);
        }
    }

    cout << sum;
}
