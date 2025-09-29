#include <iostream>
using namespace std;

int main(){
    int l;
    cin >> l;
    cin.ignore();
    for(int k = 0; k < l; k++){
        string in;
        getline(cin , in);

        bool tag = true;
        for(int i = 1; i+2 < in.size(); i+=3){
            if(in[i] == in[i+2])
                tag = false;
        }
        if(in[0] == in[in.size()-1])
            tag = false;
        if(in.size() == 2)
            tag = false;

        if(tag)
            cout << "LOOP" << endl;
        else
            cout << "NO LOOP" << endl;
    }
}
