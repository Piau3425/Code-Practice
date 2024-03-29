#include <iostream>
#include <algorithm>
using namespace std;

bool consn(int ary[], int siz);

int main(){
    int n;
    while(cin >> n){
        int ary[n];
        for(int i = 0; i < n; i++)
            cin >> ary[i];

        sort(ary, ary+n);

        if(consn(ary, n))
            cout << ary[0] << " " << ary[n-1] << " yes" << endl;
        else
            cout << ary[0] << " " << ary[n-1] << " no" << endl;
    }
}

bool consn(int ary[], int siz){
    for(int i = 0; i < siz-1; i++){
        if(ary[i]+1 != ary[i+1])
            return false;
    }

    return true;
}
