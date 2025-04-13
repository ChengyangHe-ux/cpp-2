#include <bits/stdc++.h>
using namespace std;

int main() {
    int M;
    cin>>M;

    vector<int>sum(M+2,0);
    
    for(int i=1;i<=M;i++){
        sum[i]=sum[i-1]+i;
    }

    int l=1,r=2;
    while(l<r&&r<=M){
        if(sum[r]-sum[l-1]==M){
            cout<<l<<" "<<r<<endl;
            r++;
        }else if(sum[r]-sum[l-1]>M){
            l++;
        }else{
            r++;
        }
    }
    return 0;
}
