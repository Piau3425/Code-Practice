#include <iostream>
#include <vector>
using namespace std;

vector<int> v, divid;
int t, amount, maxx, sum = 0, x;
bool can = false;

int main(){
    cin >> t >> amount;

    for(int i = 0; i < t; i++){
        cin >> x;
        maxx = x;
        for(int j = 0; j < amount-1; j++){
            cin >> x;
            maxx = max(maxx, x);
        }
        v.push_back(maxx);
        sum += maxx;
    }
    cout << sum << endl;

    int i = 0;
    for(int i = 0; i < v.size(); i++){
        if(sum%v[i] == 0){
            divid.push_back(v[i]);
            can = true;
        }
    }

    if(!can)
        cout << "-1";
    else{
        for(int i = 0; i < divid.size(); i++){
            cout << divid[i];
            if(i+1 >= divid.size())
                break;
            cout << " ";
        }
    }
}
