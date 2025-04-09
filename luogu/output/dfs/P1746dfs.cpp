#include <bits/stdc++.h>
using namespace std;
int dx[]={1,-1, 0, 0};
int dy[]={0, 0, 1,-1};
int n;
int mincnt=1e9;
void dfs(int si,int sj,int ei,int ej,vector<vector<int>>&MP,vector<vector<bool>>&visited,int depth){
    if(si==ei&&sj==ej) {
        mincnt=min(mincnt,depth);
        return;
    }
    visited[si][sj]=1;
    for(int k=0;k<4;k++){
        int x=si+dx[k];
        int y=sj+dy[k];
        if(x<1||x>n||y<1||y>n||visited[x][y]||MP[x][y]==1)continue;
        dfs(x,y,ei,ej,MP,visited,depth+1);
    }
    visited[si][sj]=0;
}
int main(){
    cin>>n;
    vector<vector<int>>MP(n+1,vector<int>(n+1,1));
    vector<vector<bool>>visited(n+1,vector<bool>(n+1,0));
    string line;
    for (int i = 1; i <=n; ++i) {
        cin >> line;
        for (int j = 1; j <=n; ++j) {
            MP[i][j] = line[j] - '0'; // ×Ö·û×ªÊý×Ö
        }
    }
    int si,sj,ei,ej;
    cin>>si>>sj>>ei>>ej;
    dfs(si,sj,ei,ej,MP,visited,0);
    cout<<mincnt<<endl;

    return 0;
}