#include <iostream>
using namespace std;

int main(){
    int count = 0;
    string id;
    cin >> id;
    for(int i = 0; i < id.length(); i++){
        if(id[i] == '8')
            count++;
    }

    cout << id << " can get " << count*10 << "% off.";
}