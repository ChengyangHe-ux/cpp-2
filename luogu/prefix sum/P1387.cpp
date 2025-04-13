#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;

    vector<vector<int>>M(n,vector<int>(m,0));
    vector<vector<int>>dp(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>M[i][j];
        }
    }
    int maxlen=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(M[i][j]==1){
                if(i==0||j==0){
                    dp[i][j]=1;
                }else{
                    dp[i][j]=min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]})+1;
                }
                maxlen=max(maxlen,dp[i][j]);
            }else{
                dp[i][j]=0;
            }
        }
    }
    cout<<maxlen<<endl;


    return 0;
}