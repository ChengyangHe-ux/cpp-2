/*
0 0 0 0 0 
0 0 0 0 0 黑色13个 
0 0 0 0 0 白色12个
0 0 0 0 0
0 0 0 0 0
*/
#include <bits/stdc++.h>
using namespace std;
#define N 5
int count1=0;
void dfs(vector<vector<int>>&mapp,int depth,int white,int black){
    if(depth==25){
        if (white > 13 || black > 12) return;
        if(white==13&&black==12){
            for(int i=0;i<5;i++){
                int x=mapp[i][0]+mapp[i][1]+mapp[i][2]+mapp[i][3]+mapp[i][4];
                if(x==5||x==0) return;
                int y=mapp[0][i]+mapp[1][i]+mapp[2][i]+mapp[3][i]+mapp[4][i];
                if(y==5||y==0) return;
               
            }
            int m=mapp[0][0]+mapp[1][1]+mapp[2][2]+mapp[3][3]+mapp[4][4];
            if(m==5||m==0) return;
            count1++;
        }else{
            return;
        }
    }
    int x=depth/5;
    int y=depth%5;
    mapp[x][y]=1;
    dfs(mapp,depth+1,white+1,black);
    mapp[x][y]=0;
    dfs(mapp,depth+1,white,black+1);
}
int main(){
    vector<vector<int>>mapp(N,vector<int>(N,0));
    dfs(mapp,0,0,0);
    cout<<count1<<endl;
    return 0;
}