#include <iostream>
#include <queue>
using namespace std;

int main(){
    int n;
    while(cin >> n && n){
        priority_queue<long long int, vector<long long int>, greater<long long int>> pq;
        long long int sum = 0;
        for(int i = 0; i < n; i++){
            int tmp;
            cin >> tmp;
            pq.push(tmp);
        }

        while(pq.size() > 1){
            int a = pq.top(); pq.pop();
            int b = pq.top(); pq.pop();
            sum += a+b;
            pq.push(a+b);
        }

        cout << sum << endl;
    }
}
