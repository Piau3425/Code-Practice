#include<iostream>
using namespace std;

struct player{
    char id;
    int now = 0;
    string card[13];
};

int main(){
    player pla[4];
    for(int i = 0; i < 4; i++){
        cin >> pla[i].id;
        for(int j = 0; j < 13; j++){
            cin >> pla[i].card[j];
        }
    }

    int p = 0, rotat = 1, sum;
    for(;; p = (p+rotat+4)%4){
        string crt = pla[p].card[pla[p].now];
        if(crt == "A")
            sum = 0;
        else if(crt == "4")
            rotat *= -1;
        else if(crt == "5" || crt == "J"){}
        else if(crt == "10"){
            if(sum+10 > 99)
                sum -= 10;
            else
                sum += 10;
        }
        else if(crt == "Q"){
            if(sum+20 > 99)
               sum -= 20;
            else
               sum += 20;
        }
        else if(crt == "K")
            sum = 99;
        else{
            sum += stoi(crt);
        }

        //cout << pla[p].id << " " << pla[p].now << " " << sum << endl;

        if(sum > 99){
            cout << pla[p].id << endl << 13-pla[p].now-1;
            break;
        }
        else if(pla[p].now == 12){
            cout << pla[p].id << endl << sum;
            break;
        }
        pla[p].now++;
    }
}