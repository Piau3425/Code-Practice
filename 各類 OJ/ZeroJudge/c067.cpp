#include <iostream>
#include <cstring>
using namespace std;

int n, sum = 0, avg, moves = 0, sett = 1;

int main(){
    while(1){
        cin >> n;
        if(n == 0)
            return 0;
        int lego[n];

        for(int i = 0; i < n; i++){
            cin >> lego[i];
            sum += lego[i];
        }

        avg = sum/n;

        for(int i = 0; i < n; i++){
            if(lego[i] > avg)
                moves += lego[i]-avg;
        }

        cout << "Set #" << sett << endl << "The minimum number of moves is " << moves << "." << endl;
        sett++, moves = 0, sum = 0;
        memset(lego, 0, sizeof(lego));
    }
}
