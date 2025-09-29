#include <iostream>
#include <queue>
using namespace std;

int loop, tmp, k;
queue<int> q;

int main(){
    cin >> loop;

    for(int i = 0; i < loop; i++){
        cin >> k;
        switch(k){
            case 1:
                cin >> tmp;
                q.push(tmp);
                break;
            case 2:
                if(q.empty())
                    cout << "-1" << endl;
                else
                    cout << q.front() << endl;
                break;
            case 3:
                if(!q.empty())
                    q.pop();
                break;
        }
    }
}
