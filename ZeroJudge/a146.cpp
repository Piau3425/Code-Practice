#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int main(){ ios_base::sync_with_stdio(0); cin.tie(0);
    int n, k;
    while(cin >> n >> k){
        if(k > n)
            k = n;
        vector<int> input(n), save(n);
        deque<pair<int, int>> dq;

        for(int i = 0; i < n; i++)
            cin >> input[i];

        for(int i = 0; i < n; i++){
            while(dq.size() && dq.front().second <= i-k)
                dq.pop_front();
            
            if(dq.size())
                save[i] = min(input[i], dq.front().first);
            else
                save[i] = input[i];

            while(dq.size() && dq.back().first >= input[i])
                dq.pop_back();

            dq.push_back({input[i], i});
            /*for(auto val : dq)
                cout << val.first << " ";
            cout << '\n';*/
        }

        for(int i = k-1; i < n; i ++)
            cout << save[i] << "\n "[i+1 < n];

        dq.clear();
        for(int i = 0; i < n; i++){
            while(dq.size() && dq.front().second <= i-k)
                dq.pop_front();
            
            if(dq.size())
                save[i] = max(input[i], dq.front().first);
            else
                save[i] = input[i];

            while(dq.size() && dq.back().first <= input[i])
                dq.pop_back();

            dq.push_back({input[i], i});
            /*for(auto val : dq)
                cout << val.first << " ";
            cout << '\n';*/
        }

        for(int i = k-1; i < n; i ++)
            cout << save[i] << "\n "[i+1 < n];
    }
}