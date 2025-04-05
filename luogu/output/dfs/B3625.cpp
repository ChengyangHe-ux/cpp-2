#include <bits/stdc++.h>
using namespace std;
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
int n,m;
vector<vector<char>>mapp;
vector<vector<bool>>vis;
bool dfs(int sx,int sy,int ex,int ey){
    vis[sx][sy]=true;
    if(sx==ex&&sy==ey){
        return true;
    }
    for(int k=0;k<4;k++){
        int xx=dx[k]+sx;
        int yy=dy[k]+sy;
        if(xx>0&&xx<=n&&yy>0&&yy<=m&&mapp[xx][yy]!='#'&&vis[xx][yy]==false){
            if(dfs(xx,yy,ex,ey)){
                return true;
            }
        }
    }
    return false;
}   
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n>>m;
    mapp.assign(n+1,vector<char>(m+1));
    vis.assign(n+1,vector<bool>(m+1,false));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>mapp[i][j];
        }
    }
    if(dfs(1,1,n,m)){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
    return 0;
}