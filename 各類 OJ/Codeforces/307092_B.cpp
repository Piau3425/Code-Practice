#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m), result;

    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < m; i++)
        cin >> b[i];

    for(int i = 0, num = 0; i < m; i++){
        while(num < a.size() && a[num] < b[i])
            num++;
        cout << num << ' ';
    }
}