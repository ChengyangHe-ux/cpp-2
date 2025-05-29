#include <bits/stdc++.h>
using namespace std;
int main(){
    set<int> P;
    int n;
    cin>>n;
    vector<int> A(n,0);
    for(int i=0;i<n;i++){
        cin>>A[i];
        P.insert(A[i]);    
    }
    for(auto i=P.begin();i!=P.end();i++){
        int count=0;
        int num=*i;
        for(int j=0;j<n;j++){
            if(num==A[j])count++;
        }
        cout<<*i<<" "<<count<<endl;
    }

    return 0;
}
