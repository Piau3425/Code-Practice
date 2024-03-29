#include <iostream>
using namespace std;

int main(){
    int total, tmp, sum, hs = -1e9;
    cin >> total;
    int mush[total];
    for(int i = 0; i < total; i++)
        cin >> mush[i];

    for(int i = 0; i < total; i++){
        for(int j = i; j < total; j++){
            if(i == j)
                sum = mush[j];
            else
                sum += mush[j];

            hs = max(hs, sum);
        }
    }
    hs = max(hs, 0);

    cout << hs;
}
