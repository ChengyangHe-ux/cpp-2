#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct Node{
    int index;
    ll num;
};
bool cmp(Node &A,Node &B){
    return A.num<B.num;
}
int main(){
    int n;
    ll limit;
    cin>>n>>limit;

    vector<Node> M;
    
    for(int i=0;i<n;i++){
        ll x;
        cin>>x;
        M.push_back({i,x});
    }
    sort(M.begin(),M.end(),cmp);
    
    int left=0;
    int right=n-1;
    while(left<right){
        if(M[left].num+M[right].num==limit){
            if(M[left].index<M[right].index){
                cout<<M[left].index<<" "<<M[right].index<<endl;
            }else{
                cout<<M[right].index<<" "<<M[left].index<<endl;
            }
            return 0;
        }else if(M[left].num+M[right].num>limit){
            right--;    
        }else{
            left++;
        }
    }
    cout<<"-1"<<endl;
    return 0;
}