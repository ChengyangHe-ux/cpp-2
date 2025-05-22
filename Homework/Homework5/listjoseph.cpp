#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,k;
    cin>>N>>k;
    list<int>p;
    for(int i=1;i<=N;i++){
        p.push_back(i);
    }
    auto it=p.begin();
    while(!p.empty()){
        for(int i=1;i<k;i++){
            it++;
            if(it==p.end())it=p.begin();
        }
        cout<<*it<<" ";
        it=p.erase(it);
        if(it==p.end())it=p.begin();
    }
    return 0;
}