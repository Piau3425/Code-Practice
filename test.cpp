#include <iostream>
#include <locale> // 包含 locale 標頭檔
#include <codecvt> // 包含 codecvt 標頭檔
using namespace std;

int sum = 0;

int f(int n){
    sum += n;
    return n && f(n-1);
}

int main() {
    int a;
    cin >> a;
    f(a);
    cout << sum;
}
