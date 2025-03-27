#include <bits/stdc++.h>
using namespace std;
using ll=long long;

struct Edge{
    int to;
    ll w;
};
int main(){
    int n;
    cin>>n;
    
    vector<vector<Edge>>adj(n+1);

    for(int i=2;i<=n;i++){
        int x;
        ll y;
        cin>>x>>y;
        adj[x].push_back({i,y});
        adj[i].push_back({x,y});
    }
    
    




    return 0;
}