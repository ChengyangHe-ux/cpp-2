#include <bits/stdc++.h>
using namespace std;
int get_ans(int l,int r){
    return r-l;
}
int main(){
    int t;
    cin>>t;
    while (t--){
        int l,r;
        cin>>l>>r;
        int k=get_ans(l,r);
        cout<<k<<endl;
    }
    return 0;
}