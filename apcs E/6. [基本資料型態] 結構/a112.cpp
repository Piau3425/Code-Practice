#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

struct data{
    string loc;
    vector<string> name;
    vector<int> amount;
};


int main(){
    vector<data> d;
    int loop;
    cin >> loop;

    for(int k = 0; k < loop; k++){
        int tmpa;
        bool locExist = false;
        string tmpn, tmpl;
        cin >> tmpn >> tmpa >> tmpl;

        for(int i = 0; i < d.size(); i++){
            if(d[i].loc == tmpl){
                bool namExist = false;
                for(int j = 0; j < d[i].name.size(); j++){
                    if(d[i].name[j] == tmpn){
                        d[i].amount[j] += tmpa;
                        namExist = true;
                        locExist = true;
                    }
                }
                if(!namExist){
                    d[i].name.push_back(tmpn);
                    d[i].amount.push_back(tmpa);
                    locExist = true;
                }
            }
        }
        if(!locExist){
            data tmp;
            tmp.loc = tmpl;
            tmp.name.push_back(tmpn);
            tmp.amount.push_back(tmpa);
            d.push_back(tmp);
        }
    }

    for(int i = 0; i < d.size(); i++){
        cout << d[i].loc << ":";
        for(int j = 0; j < d[i].name.size(); j++){
            cout << d[i].name[j] << " " << d[i].amount[j] << ",\n"[j == d[i].name.size()-1];
        }
    }
}
