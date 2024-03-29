#include <iostream>
#include <cstring>
using namespace std;

string str;
int weight[10], maxx = -1, loop;
char site[10][100];

int main(){
    cin >> loop;

    for(int k = 0; k < loop; k++){
        for(int i = 0; i < 10; i++){
            cin >> str >> weight[i];
            strcpy(site[i], str.c_str());
            maxx = max(maxx, weight[i]);
        }

        cout << "Case #" << k+1 << ":\n";

        for(int i = 0; i < 10; i++){
            if(weight[i] == maxx){
                for(int j = 0; site[i][j] != '\0'; j++)
                    cout << site[i][j];
            }
            cout << endl;
        }

        maxx = -1;
        memset(site, '\0', sizeof(site));
    }
}
