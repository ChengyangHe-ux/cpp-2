#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    list<int> M;
    for(int i=1;i<=n;i++){
        M.push_back(i);
    }
    int k;
    cin>>k;
    auto it=M.begin();
    while(!M.empty()){
        for(int i=1;i<k;i++){
            it++;
            if(it==M.end())it=M.begin();
        }
        cout<<*it<<" ";
        it=M.erase(it);
        if(it==M.end())it=M.begin();
    }
    return 0;
}