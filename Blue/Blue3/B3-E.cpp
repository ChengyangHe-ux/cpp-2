#include <bits/stdc++.h>
using namespace std;
#define N 1e5
struct node{
    int x;
    int y;
};
bool check(vector<node>&a,int k,int len){
    int cnt=0;
    for(int i=0;i<a.size();i++){
        cnt+=(a[i].x/len)*(a[i].y/len);
        if(cnt>=k)return true;
    }
    return cnt>=k;
}
int main(){
    int n,k;
    cin>>n>>k;
    vector<node>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i].x>>a[i].y;
    }
    int left=1,right=N,ans=0;
    while(left<=right){
        int mid=(left+right)/2;
        if(check(a,k,mid)){
            ans=mid;
            left=mid+1;
        }else{
            right=mid-1;
        }
    }
    cout<<ans<<endl;

    return 0;
}