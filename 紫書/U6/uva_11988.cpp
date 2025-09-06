#include<bits/stdc++.h>
using namespace std;

main(){string s;while(cin>>s){deque<char> dq;int k=0;for(auto &c:s){if(c == '[')k=0;else if(c==']')k=dq.size();else dq.insert(dq.begin()+k,c),k++;}for(auto &c:dq)cout<<c;cout<<'\n';}}