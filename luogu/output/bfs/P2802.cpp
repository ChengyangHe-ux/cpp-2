#include <bits/stdc++.h>
using namespace std;

int dx[]={1,-1, 0, 0};
int dy[]={0, 0, 1,-1};
struct State{
    int x,y,hp,dist;
};
int main(){
    int n,m;
    cin>>n>>m;
    int sx,sy,tx,ty;
    vector<vector<int>>MP(n,vector<int>(m,0));
    vector<vector<vector<bool>>> visited(n, vector<vector<bool>>(m, vector<bool>(7, false)));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>MP[i][j];
            if(MP[i][j]==2){
                sx=i;
                sy=j;
            }
            if(MP[i][j]==3){
                tx=i;
                ty=j;
            }
        }
    }
    queue<State>q;
    visited[sx][sy][6]=true;
    q.push({sx,sy,6,0});
    while(!q.empty()){
        State s=q.front();
        q.pop();
        if(MP[s.x][s.y]==3){
            cout<<s.dist<<endl;
            return 0;
        }
        for(int k=0;k<4;k++){
            int x2=s.x+dx[k];
            int y2=s.y+dy[k];
            int nhp=s.hp-1;
            if(x2<0||x2>=n||y2<0||y2>=m)continue;
            if(MP[x2][y2]==0||nhp==0)continue;
            if(MP[x2][y2]==4) nhp=6;
            if(!visited[x2][y2][nhp]){
                visited[x2][y2][nhp]=true;
                q.push({x2,y2,nhp,s.dist+1});
            }
        }
    }   
    cout<<-1<<endl;
    return 0;
}