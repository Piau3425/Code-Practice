#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(pair<char, int> a, pair<char, int> b){
    if(a.second == b.second)
        return a.first < b.first;
    else
        return a.second > b.second;
}

int main(){
    int n, a[26] = {0};
    cin >> n;
    cin.ignore();
    for(int i = 0; i < n; i++){
        string input;
        getline(cin, input);
        for(int j = 0; j < input.length(); j++)
            a[toupper(input[j]) - 'A']++;
    }

    pair<char, int> p[26];
    for(int i = 0; i < 26; i++){
        p[i].first = i+'A';
        p[i].second = a[i];
    }

    sort(p, p+26, cmp);
    for(int i = 0; p[i].second != 0; i++)
        cout << p[i].first << " " << p[i].second << '\n';
}