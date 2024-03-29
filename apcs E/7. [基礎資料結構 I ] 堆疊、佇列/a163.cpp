#include <iostream>
#include <queue>
using namespace std;

int main(){
    int group;
    cin >> group;
    for(int k = 0; k < group; k++){
        int n, m;
        cin >> n >> m;
        int pri[n], maxpri = 0, minute = 0;
        queue<int> q;
        for(int i = 0; i < n; i++){
            cin >> pri[i];
            maxpri = max(maxpri, pri[i]);
            q.push(i);
        }

        while(!(pri[q.front()] >= maxpri && q.front() == m)){
            if(pri[q.front()] >= maxpri){
                minute++;
                q.pop();
                maxpri = 0;
                queue<int> tmp = q;
                while(!tmp.empty()){
                    maxpri = max(maxpri, pri[tmp.front()]);
                    tmp.pop();
                }
            }
            else{
                q.push(q.front());
                q.pop();
            }
        }
        minute++;
        cout << minute << endl;
    }
}
