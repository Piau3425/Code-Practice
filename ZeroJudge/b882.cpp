#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    long long h, m, s;
    cin >> h >> m >> s;

    m += s/60;
    s %= 60;
    h += m/60;
    m %= 60;
    h %= 24;

    cout << setfill('0') << setw(2) << h << ":" << setfill('0') << setw(2) << m << ":" << setfill('0') << setw(2) << s;
}