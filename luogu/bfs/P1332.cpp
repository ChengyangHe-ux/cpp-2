#include <bits/stdc++.h>
using namespace std;
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
int main(){
    int n,m,a,b;
    cin>>n>>m>>a>>b;
    vector<vector<int>>M(n,vector<int>(m,1e9));
    queue<pair<int,int>>q;
    while(a--){
        int x1,y1;
        cin>>x1>>y1;
        x1--;
        y1--;
        M[x1][y1]=0;
        q.push({x1,y1});
    }
    while(!q.empty()){
        auto [x,y]=q.front();q.pop();
        for(int k=0;k<4;k++){
            int x2=x+dx[k];
            int y2=y+dy[k];
            if(x2<0||x2>=n||y2<0||y2>=m)continue;
            if(M[x2][y2]>(M[x][y]+1)){
                M[x2][y2]=M[x][y]+1;
                q.push({x2,y2});
            }
        }
    }
    while(b--){
        int x4,y4;
        cin>>x4>>y4;
        x4--;
        y4--;
        cout<<M[x4][y4]<<endl;
    }
    return 0;
}