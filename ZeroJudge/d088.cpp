#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<stack<string>> v(52);
bool flag;

void move(int i){
    if(i-3 >= 0 && (v[i].top()[0] == v[i-3].top()[0] || v[i].top()[1] == v[i-3].top()[1])){
        flag = true;
        v[i-3].push(v[i].top());
        v[i].pop();
        if(v[i].empty()) v.erase(v.begin() + i);
        move(i-3);
    }
    else if(i-1 >= 0 && (v[i].top()[0] == v[i-1].top()[0] || v[i].top()[1] == v[i-1].top()[1])){
        flag = true;
        v[i-1].push(v[i].top());
        v[i].pop();
        if(v[i].empty()) v.erase(v.begin() + i);
        move(i-1);
    }
}

int main(){
    while(1){
        v.clear(); v.resize(52);
        for(int i = 0; i < 52; i++){
            string tmp;
            cin >> tmp;
            if(tmp == "#") return 0;
            v[i].push(tmp);
        }

        flag = true;
        while(flag){
            flag = false;

            for(int i = 1; i < v.size(); i++){
                move(i);
                if(flag) break;
            }
        }
		
		cout << v.size() << " pile" << (v.size() == 1 ? " " : "s ") << "remaining: ";
        for(int i = 0; i < v.size(); i++) cout << (i ? " " : "") << v[i].size();
        cout << '\n';
    }
}
