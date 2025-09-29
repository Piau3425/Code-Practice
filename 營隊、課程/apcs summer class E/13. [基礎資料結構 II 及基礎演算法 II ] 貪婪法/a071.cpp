#include <iostream>
#include <queue>
using namespace std;

int main(){

    int n, m, time;
    priority_queue<int, vector<int>, greater<>> q;
    cin >> n >> m;
    n -= m;
    while(m--){
        cin >> time;
        q.push(time);
    }
    while(n--){
        cin >> time;
        time += q.top();
        q.pop();
        q.push(time);
    }
    
    time = -1;
    while(q.size()){
        time = max(time, q.top());
        q.pop();
    }

    cout << time;
}