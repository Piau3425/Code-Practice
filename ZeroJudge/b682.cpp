#include <iostream>
using namespace std;

int h1, h2, m1, m2;

int main(){
        cin >> h1 >> m1 >> h2 >> m2;
        if(h2 > h1)
            cout << ((h2-h1)*60+(m2-m1))/60 << " " << ((h2-h1)*60+(m2-m1))%60;
        else if(h2 < h1 || (h2 == h1 && m2 < m1))
            cout << ((h2+24-h1)*60+(m2-m1))/60 << " " << ((h2+24-h1)*60+(m2-m1))%60;
        else
            cout << "0 " << m2-m1;
}
