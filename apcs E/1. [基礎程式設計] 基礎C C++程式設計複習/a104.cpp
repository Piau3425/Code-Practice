#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

int n, sum[75] = {1, 0}, temp[75] = {2, 0}, flag = 74;
int double_it(int a[]);
int add(int a[], int b[]);

int main(){
    cin >> n;
    for(int k = 2; k <= n; k++){
        for(int i = 0; i < (k-1)*2-1; i++)
            double_it(temp);
        /*for(int i = 0; i < 75; i++)
            cout << temp[i];
        cout << endl;*/
        add(sum, temp);
        memset(temp, 0, sizeof(temp));
        temp[0] = 2;

    }
    while(sum[flag] == 0)
        flag--;
    for(int i = flag; i >= 0; i--)
        cout << sum[i];

}

int double_it(int a[]){
    //cout << "double! ";
    for(int i = 0; i < 75; i++)
        a[i] *= 2;
    for(int i = 0; i < 75; i++){
        if(a[i] >= 10){
            a[i+1] += a[i]/10;
            a[i] %= 10;
        }
    }
}

int add(int a[], int b[]){
    for(int i = 0; i < 75; i++)
        a[i] += b[i];
    for(int i = 0; i < 75; i++){
        if(a[i] >= 10){
            a[i+1] += a[i]/10;
            a[i] %= 10;
        }
    }
}
