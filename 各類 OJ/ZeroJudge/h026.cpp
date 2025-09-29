#include <iostream>
#include <vector>
using namespace std;

int start, loop, bruh, sisB = -999;
int* sis;
bool same = false;


int wl(int bruh, int sis);

int main(){
    cin >> start >> loop;
    sis = new int[loop];


    for(int i = 0; i < loop; i++)
        cin >> sis[i];

    bruh = start;
    for(int i = 0; i < loop; i++){
        cout << bruh << " ";
        if(wl(bruh, sis[i]) == 1){
            cout << ": Won at round " << i+1;
            return 0;
        }
        else if(wl(bruh, sis[i]) == -1){
            cout << ": Lost at round " << i+1;
            return 0;
        }

        if(sis[i] == sisB)
            same = true;
        else
            same = false;
        sisB = sis[i];

        if(same){
            if(sis[i] == 0)
                bruh = 5;
            else if(sis[i] == 2)
                bruh = 0;
            else if(sis[i] == 5)
                bruh = 2;
        }
        else{
            if(sis[i] == 0)
                bruh = 0;
            else if(sis[i] == 2)
                bruh = 2;
            else if(sis[i] == 5)
                bruh = 5;
        }
    }

    cout << ": Drew at round " << loop;
}

int wl(int bruh, int sis){
    if((bruh == 0 && sis == 2) || (bruh == 2 && sis == 5) || (bruh == 5 && sis == 0))
        return 1;
    else if(bruh == sis)
        return 0;
    else
        return -1;
}
