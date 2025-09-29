    #include <iostream>
    #include <vector>
    using namespace std;

    long long fN(vector<long long>& a, int m){
        if(m == 0 || m == 1)
            return m;
        else
            return a[m-1] + a[m-2];
    }

    int main(){
        int m;
        cin >> m;
        vector<long long> a(6000);
        a[0] = 0; a[1] = 1;
        for(int i = 2; i < 6000; i++){
            a[i] = a[i-1] + a[i-2];
        }
        cout << fN(a, m-1);
    }