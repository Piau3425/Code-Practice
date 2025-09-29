#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<string> poker;
    string tmp;
    int slice;
    cin >> slice;
    cin.ignore();
    while(slice--){
        cin >> tmp;
        poker.push_back(tmp);
    }

    cin >> slice;
    for(int i = slice; i < poker.size(); i++)
        cout << poker[i] << ' ';
    for(int i = 0; i < slice-1; i++)
        cout << poker[i] << ' ';
    cout << poker[slice-1];
}