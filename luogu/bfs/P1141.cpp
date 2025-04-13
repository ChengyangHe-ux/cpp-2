#include <bits/stdc++.h>
using namespace std;
int dx[]={1,-1, 0, 0};
int dy[]={0, 0, 1,-1};
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>M(n,vector<int>(n,0));
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        for(int j=0;j<n;j++){
            M[i][j]=s[j]-'0';
        }
    }
    while(m--){
        int max1=1;
        int x,y;
        cin>>x>>y;
        x--,y--;
        vector<vector<int>>dist(n,vector<int>(n,1e9));
        queue<pair<int,int>>q;
        dist[x][y]=1;
        q.push({x,y});
        while(!q.empty()){
            auto [x,y]=q.front();q.pop();
            for(int k=0;k<4;k++){
                int x2=x+dx[k];
                int y2=y+dy[k];
                if(x2<0||x2>=n||y2<0||y2>=n)continue;
                if(M[x][y]==M[x2][y2])continue;
                if(dist[x2][y2]==1e9){
                    dist[x2][y2]=dist[x][y]+1;
                    max1++;
                    q.push({x2,y2});
                }
            }
        }
        cout<<max1<<endl;
    }


    return 0;
}