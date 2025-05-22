#include <bits/stdc++.h>
using namespace std;
void insert(int a[], int x){}
int main(){
    int n,k;
    cin>>n>>k;

    if(n==1){
        cout<<0<<endl;
        return 0;
    }
    vector<int>A(n);
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    sort(A.begin(),A.end());
    int mina=A[0];
    int maxa=A[n-1];
    if(mina+k>=maxa-k){
        cout<<0<<endl;
    }else{
        cout<<(maxa-k)-(mina+k)<<endl;
    }
    return 0;
}