#include <bits/stdc++.h>
using namespace std;
int d=0;
int mind=1e9;
vector<float>b;
void dfs(float w,vector<float>&a,int n,int m,int depth){
    if(w+b[depth]<m)return;
    if(depth==n){
        if(w==m&&d<mind){
            mind=d;
        }
        return;
    } 

        if(a[depth]+w<=m){

            dfs(w+a[depth],a,n,m,depth+1);
        }
    //要这半个瓜
        if(a[depth]/2+w<=m){
            d++;
            dfs(w+a[depth]/2,a,n,m,depth+1);
            d--;
        }
    //不要这个瓜
        dfs(w,a,n,m,depth+1);
    }
int main(){
    int n,m;
    cin>>n>>m;
    vector<float> a(n);
    
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end(),greater<float>());
    b.resize(n+1);
    b[n-1]=a[n-1];
    for(int i=n-2;i>=0;i--){
        b[i]=b[i+1]+a[i];
    }
    dfs(0,a,n,m,0);
    if(mind==1e9){
        cout<<-1<<endl;
    }else{
        cout<<mind<<endl;
    }
    return 0;
}