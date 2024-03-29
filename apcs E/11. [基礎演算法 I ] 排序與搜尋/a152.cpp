#include <iostream>
using namespace std;

int bs(int ary[], int L, int R, int key);

int freq;

int main(){
    int len, key;
    cin >> len;
    int ary[len];
    for(int i = 0; i < len; i++)
        cin >> ary[i];
    cin >> key;

    int ans = bs(ary, 0, len-1, key);
    if(ans == -1)
        cout << "not found " << freq;
    else
        cout << ans << " " << freq;
}

int bs(int ary[], int L, int R, int key){
    if(L > R)
        return -1;

    freq++;
    int M = L+(R-L)/2;
    if(ary[M] == key)
        return M;
    else if(ary[M] < key)
        bs(ary, M+1, R, key);
    else
        bs(ary, L, M-1, key);
}
