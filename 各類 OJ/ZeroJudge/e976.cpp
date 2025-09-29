#include <iostream>
using namespace std;

int main(){
    int h, m, s;
    while(cin >> h >> m >> s)
        cout << h << " " << m << " " << s << ". I will " << (h*s >= m ? "make it!\n" : "be late!\n");
}