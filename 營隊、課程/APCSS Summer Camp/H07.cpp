#include <iostream>
#include <algorithm>
using namespace std;

struct player{
    int atk = -1;
    int def = -1;
    int value = -999;
};

bool cmp(player a, player b){
    return a.value > b.value;
}

int main(){
    int n;
    cin >> n;
    player p[20];
    for(int i = 0; i < n; i++){
        cin >> p[i].atk >> p[i].def;
        p[i].value = p[i].atk*p[i].atk+p[i].def*p[i].def;
    }
    sort(p, p+n, cmp);

    cout << p[1].atk << " " << p[1].def;
}