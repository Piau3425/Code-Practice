#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

void merge(vector<int>& array, int l, int mid, int r){
    vector<int> lsub(array.begin() + l, array.begin() + mid+1), rsub(array.begin() + mid+1, array.begin() + r + 1);
    int lidx = 0, ridx = 0;
    lsub.push_back(1e9);
    rsub.push_back(1e9);

    for(int i = l; i <= r; i++){
        if(lsub[lidx] <= rsub[ridx]){
            array[i] = lsub[lidx];
            lidx++;
        }
        else{
            array[i] = rsub[ridx];
            ridx++;
        }
    }
}

void mergeSort(vector<int>& array, int l, int r){
    if(l < r){
        int mid = (l+r)/2;
        mergeSort(array, l, mid);
        mergeSort(array, mid+1, r);
        merge(array, l, mid, r);
    }
}

int main(){
    vector<int> v;
    stringstream ss;
    string input;
    getline(cin, input);
    ss.str(input);
    while(ss >> input)
        v.push_back(stoi(input));

    mergeSort(v, 0, v.size()-1);

    for(int val : v)
        cout << val << " ";
}