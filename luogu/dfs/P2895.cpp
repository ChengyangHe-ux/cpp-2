#include <bits/stdc++.h>
using namespace std;
struct bomb{
    int x,y,t;
};
int dx[]={1,0,0};
int dy[]={0,1,0};
int ans=1e9;
int M;
int n=400;
vector<bomb> b(M);
vector<vector<int>>mapp(n,vector<int>(n,0));
vector<vector<bool>>vis(n,vector<bool>(n,0));
void dfs(int t,int maxt,int wt,int x,int y){
    vis[x][y]=true;
    if(t>maxt){
        ans=min(ans,wt);
        return;
    }
    //Ñ¡Ôñ¼ÌÐø×ß
    for(int i=0;i<2;i++){
        int sx=x+dx[i];
        int sy=y+dy[i];
        
    }

}
bool cmp(const bomb &a,const bomb &b){
    return a.t<b.t;
}
int main(){
    cin>>M;
    for(int i=0;i<M;i++){
        cin>>b[i].x>>b[i].y>>b[i].t;
    }
    
    sort(b.begin(),b.end(),cmp);
    int maxt=b[M-1].t;
    dfs(0,maxt);





    return 0;
}