#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin>>N;
    vector<int>MP(N+1,0);
    for(int i=1;i<=N;i++){
        cin>>MP[i];
    }
    queue<int>q;
    vector<int>dist(N+1,1e9);
    dist[1]=0;
    q.push(1);
    while(!q.empty()){
        int x=q.front();
        q.pop();
        if(x==N){cout<<dist[N]<<endl;return 0;}
        for(int i=1;i<=MP[x];i++){
            if(x+i<=N&&dist[x+i]==1e9){
                dist[x+i]=dist[x]+1;
                q.push(x+i);
            }
        }
    }
    cout<<-1<<endl;
    return 0;
}