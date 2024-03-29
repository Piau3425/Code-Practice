#include <iostream>
using namespace std;

int h1, h2, m1, m2;

int main(){
    while(1){
        cin >> h1 >> m1 >> h2 >> m2;
        if(h1+h2+m1+m2 == 0)
            return 0;

        if(h2 > h1)
            cout << (h2-h1)*60+(m2-m1);
        else if(h2 < h1 || (h2 == h1 && m2 < m1))
            cout << (h2+24-h1)*60+(m2-m1);
        else
            cout << m2-m1;

        cout << endl;
    }
}
