#include <iostream>
using namespace std;

int loop, a, b, odd = 0;

int main(){
    cin >> loop;

    for(int k = 0; k < loop; k ++){
        cin >> a >> b;

        for(int i = a; i <= b; i++){
            if(i%2 == 1)
                odd += i;
        }

        cout << "Case " << k+1 << ": " << odd << endl;
        odd = 0;
    }
}
