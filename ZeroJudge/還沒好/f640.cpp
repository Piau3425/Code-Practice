#include <iostream>
using namespace std;

void d(char n){
    if(n == 'f')
}

int f(char n){
    if(isalpha(n))
        d(n);
    if(isdigit(n))
        return 2*(n-'0')-3;

}



int main(){
    char n;
    while(cin >> n && n != '\n'){
        if(n == 'f')
            f()
    }
}


