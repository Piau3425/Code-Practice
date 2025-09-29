#include <iostream>
using namespace std;

int balance, timebreak, eating, tim = 0;

int main(){
    cin >> balance >> timebreak >> eating;

    if((eating && balance < 55) || (!eating && balance < 32)){
        cout << "Wayne can't eat and drink.";
        return 0;
    }
    while(1){
        if(eating && balance >= 55){
            balance -= 55;
            if(balance == 1)
                cout << tim << ": Wayne drinks a Corn soup, and now he has " << balance << " dollar.\n";
            else if(balance > 0)
                cout << tim << ": Wayne drinks a Corn soup, and now he has " << balance << " dollars.\n";
            else
                cout << tim << ": Wayne drinks a Corn soup, and now he doesn't have money.\n";
        }
        else if(!eating && balance >= 32){
            balance -= 32;
            if(balance == 1)
                cout << tim << ": Wayne eats an Apple pie, and now he has " << balance << " dollar.\n";
            else if(balance > 0)
                cout << tim << ": Wayne eats an Apple pie, and now he has " << balance << " dollars.\n";
            else
                cout << tim << ": Wayne eats an Apple pie, and now he doesn't have money.\n";
        }
        else
            break;

        tim += timebreak;
        eating = !eating;
    }
}
