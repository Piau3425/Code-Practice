#include <iostream>
#include <queue>
using namespace std;

int main(){
    int n;
    while(cin >> n && n != 0){
        queue<int> q;
        for(int i = 1; i <= n; i++)
            q.push(i);
        
        cout << "Discarded cards: ";
        while(q.size() > 1){
            cout << q.front();
            q.pop();
            if(q.size() == 1)
                break;
            q.push(q.front());
            q.pop();
            cout << ", ";
        }

        cout << '\n' << "Remaining card: " << q.front() << '\n';
    }
}