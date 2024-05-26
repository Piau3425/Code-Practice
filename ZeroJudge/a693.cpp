#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, m, start, end;
    while(cin >> n >> m){
        vector<int> food(n+1);

        for(int i = 1; i <= n; i++){
            int tmp;
            cin >> tmp;
            food[i] = food[i-1] + tmp;
        }

        while(m--){
            cin >> start >> end;
            cout << food[end] - food[start-1] << '\n';
        }
    }
}