#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int gcd(int a, int b);
int lcm(int a, int b);
bool sortdef(int a, int b);
bool isleap(int n);
int MonthToDay(int m, int y);

int main(){
    vector<int> kid;
    int kids, tmp, totalDay, y, m, d;
    cin >> kids;
    for(int i = 0; i < kids; i++){
        cin >> tmp;
        kid.push_back(tmp);
    }
    sort(kid.begin(), kid.end(), sortdef);

    /*for(int i = 0; i < kid.size(); i++){
        cout << kid[i] << " ";
    }
    cout << endl;*/

    if(kids >= 3){
        totalDay = lcm(kid[0], kid[1]);
        for(int i = 2; i < kid.size(); i++){
            totalDay = lcm(totalDay, kid[i]);
        }
    }
    else if(kids == 2)
        totalDay = lcm(kid[0], kid[1]);
    else
        totalDay = kid[0];

    scanf("%d/%d/%d", &y, &m, &d);

    d += totalDay;

    while(d > MonthToDay(m, y)){
        d -= MonthToDay(m, y);
        m++;
        if(m == 13){
            y++;
            m = 1;
        }
    }
    printf("%d/%02d/%02d", y, m, d);

}


int gcd(int a, int b){
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int lcm(int a, int b){
    return a / gcd(a, b) * b;
}

bool sortdef(int a, int b){
    return a > b;
}

bool isleap(int n){
    if((n % 4 == 0 && n % 100 != 0) || n % 400 == 0)
        return true;
    else
        return false;
}

int MonthToDay(int m, int y){
    switch(m){
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;
        case 2:
            if(isleap(y))
                return 29;
            else
                return 28;
        default:
            return 30;
    }
}
