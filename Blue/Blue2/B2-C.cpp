#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        vector<int>a(n);
        vector<int> diff(n);
        cin>>a[0];
        for(int i=1;i<n;i++){
            cin>>a[i];
            diff[i]=a[i]-a[i-1]-1;
        }
        int sum=0;
        for(int i=1;i<n;i++){
            sum=sum^diff[i];
        }
        if(sum==1){
            cout<<"Alice"<<endl;
        }else{
            cout<<"Bob"<<endl;
        }
    }
    return 0;
}
//4->3
//1 3 3
//3->1
//1 1 3
//1 1 1 
//Alice