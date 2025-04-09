#include <bits/stdc++.h>
using namespace std;

int dx[]={1,-1, 0, 0};
int dy[]={0, 0, 1,-1};

int main(){
    int n;
    cin>>n;
    
    vector<vector<int>>MP(n+1,vector<int>(n+1,1));
    
    for(int i=1;i<=n;i++){
        string s;
        cin>>s;
        for(int j=1;j<=n;j++){
            MP[i][j]=s[j-1]-'0';
        }    
    }
    vector<vector<int>> dist(n+1, vector<int>(n+1, 1e9));
    queue<pair<int,int>> q;
    int si,sj,ei,ej;
    cin>>si>>sj>>ei>>ej;
    dist[si][sj]=0;
    q.push({si,sj});
    while(!q.empty()){
        auto [x,y]=q.front();
        q.pop();
        for(int k=0;k<4;k++){
            int x2=dx[k]+x;
            int y2=dy[k]+y;
            if(x2<1||x2>n||y2<1||y2>n||MP[x2][y2]==1||dist[x2][y2]!=1e9) continue;
            dist[x2][y2]=dist[x][y]+1;
            q.push({x2,y2});
        }
    }
    if(dist[ei][ej]==1e9)cout<<-1<<endl;
    else{
        cout<<dist[ei][ej]<<endl;
    }
    return 0;
}