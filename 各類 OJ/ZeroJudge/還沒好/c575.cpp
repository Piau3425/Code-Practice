#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n, m, range;
    cin >> n >> m;
    vector<int> server(n);
    for(int i = 0; i < n; i++)
        cin >> server[i];
    
    sort(server.begin(), server.end());

    for(int i = server[0]; i < server[server.size()-1];){
        
    }
}